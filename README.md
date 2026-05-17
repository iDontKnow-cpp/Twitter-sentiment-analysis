# 🐦 Twitter Sentiment Analysis

This repository contains a simple sentiment analysis application built using a Python backend and a C++ GUI frontend (via the Qt framework).

The application leverages a Logistic Regression model trained on **1.6 million tweets** from the **Sentiment140 dataset** (collected in 2009 and encoded in `ISO-8859-1`) to classify input text as either **Positive** or **Negative**.

---

## 🔹 Prerequisites

### System Requirements

* **Operating System:** Linux (The GUI application is developed using Qt and is currently tested on Linux systems).

### Python (Backend)

Ensure Python 3.x is installed along with the following libraries:

* `pandas`
* `numpy`
* `scikit-learn`
* `nltk`

### C++ & Qt (Frontend)

The frontend utilizes the Qt5 framework (specifically `QApplication` and `QProcess`). To install the necessary C++ Qt dependencies on Ubuntu/Debian-based systems, run the following command in your terminal:

```bash
sudo apt install qtbase5-dev

```

---

## 🔹 Installation & Usage

**1. Clone the repository:**
Download the project files to your local Linux machine.

**2. Compile the C++ Frontend:**
Navigate to the repository directory in your terminal and compile the main C++ file into an executable named `qt_app`. You can use a command similar to:

```bash
g++ -fPIC main.cpp -o qt_app $(pkg-config --cflags --libs Qt5Widgets)

```

**3. Set up the directory:**
Ensure that your trained model files (`trained_model.sav` or `trained_model.pkl`) and the Python backend script (`Model.py`) are located in the same directory as your compiled `qt_app` executable.

**4. Run the application:**
Execute the compiled application:

```bash
./qt_app

```

Enter a tweet into the GUI to analyze its sentiment!

---

## 🔹 How It Works

1. **Text Input:** The user enters a text string (tweet) into the Qt-based GUI.
2. **Process Communication:** The `qt_app` executable passes the text string to the Python backend utilizing `QProcess`.
3. **Backend Execution (`Model.py`):**
* Applies the exact same NLP preprocessing steps used during the training phase.
* Loads the serialized model (`trained_model.sav` or `.pkl`).
* Classifies the preprocessed text as Positive or Negative.


4. **Result Display:** The predicted sentiment is returned to the C++ frontend and displayed on the GUI.

---

## 🔹 Model Details

* **Algorithm:** Logistic Regression
* **Training Data:** 1.6 million tweets from the Sentiment140 dataset
* **Language:** Python (used for both model training and backend inference)
* **Model Output Formats:** The repository supports serialized models saved as either `trained_model.sav` or `trained_model.pkl`.

---

## 🔹 Preprocessing Techniques

To ensure accurate predictions, the input text undergoes the following Natural Language Processing (NLP) steps in both the training phase and during live inference (handled within `Model.py`):

* **Noise Removal:** Strips out special characters, punctuation, and numbers.
* **Case Folding:** Converts all text to lowercase to maintain uniformity.
* **Stopword Removal:** Filters out common, non-informative words (e.g., "the", "is", "and").
* **Stemming:** Applies the NLTK `PorterStemmer` to reduce words to their root or base form (e.g., converting "running" to "run").
