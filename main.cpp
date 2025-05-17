#include <QApplication>
#include <QPushButton>
#include <QFileDialog>
#include <QProcess>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Facial Recognition App");

    // UI elements
    QPushButton *button = new QPushButton("Select Image and Run Model");
    QLabel *imageLabel = new QLabel();
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setFixedSize(300, 300);

    QLabel *outputLabel = new QLabel();
    outputLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    outputLabel->setWordWrap(true);
    outputLabel->setFixedHeight(150);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(button);
    layout->addWidget(imageLabel);
    layout->addWidget(outputLabel);
    window.setLayout(layout);

    // Button click handler
    QObject::connect(button, &QPushButton::clicked, [&]() {
        QString imagePath = QFileDialog::getOpenFileName(
            nullptr,
            "Select Image",
            "",
            "Images (*.png *.jpg *.jpeg *.webp *.avif *.heif)");

        if (imagePath.isEmpty()) return;

        // Load and show image
        QPixmap pix(imagePath);
        if (pix.isNull()) {
            outputLabel->setText("❌ Failed to load image.");
        }
        imageLabel->setPixmap(pix.scaled(imageLabel->size(), Qt::KeepAspectRatio));

        // Run Python model
        QProcess *process = new QProcess(&window);
        process->setProgram("python3");
        process->setArguments(QStringList() << "model.py" << imagePath);

        QObject::connect(process, &QProcess::readyReadStandardOutput, [=]() {
            QString stdoutOutput = process->readAllStandardOutput();
            outputLabel->setText("✅ Output:\n" + stdoutOutput);
        });

        QObject::connect(process, &QProcess::readyReadStandardError, [=]() {
            QString stderrOutput = process->readAllStandardError();
            if (!stderrOutput.isEmpty()) {
                outputLabel->setText("⚠️ Error:\n" + stderrOutput);
            }
        });

        process->start();

        if (!process->waitForFinished()) {
            outputLabel->setText("⚠️ Python script did not finish.");
        }
    });

    window.resize(400, 500);
    window.show();

    return app.exec();
}
