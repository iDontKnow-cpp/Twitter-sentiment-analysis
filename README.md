# Twitter-sentiment-analysis
Overview:
The model is trained on the Sentiment140 dataset, which consists of 1.6 million tweets collected in 2009. Due to the age of the dataset, the text is encoded in ISO-8859-1 instead of UTF-8 (which became the standard later).
The model classifies tweets into two categories:
  Positive
  Negative

Model Details:
Algorithm Used: Logistic Regression
Language: Python (for backend & model training)
Model Output Formats:
  trained_model.sav
  trained_model.pkl
These files contain the trained model and can be used to make predictions.

Preprocessing Techniques:
The following preprocessing steps were applied to clean and prepare the tweets before training:
  Removal of special characters and numbers
  Lowercasing all text
  Removal of stopwords (e.g., "the", "is", "and")
  Stemming using PorterStemmer (e.g., "running" → "run")
The same steps are applied to any new tweet before classification to ensure consistency. This logic is implemented in Model.py.

Application Frontend:
Frontend Language: C++
Libraries Used:
  QApplication
  QProcess (used to call Python backend)
  Executable: qt_app
Note:
  The GUI application (qt_app) is built using Qt for C++ and is currently supported only on Linux OS.

How It Works:
User enters a tweet in the GUI (qt_app)
The application passes the input to the Python backend via QProcess
Model.py applies the same preprocessing
The trained model predicts the sentiment (Positive or Negative)
The result is displayed in the GUI

Requirements
Python (Backend):
  pandas
  numpy
  scikit-learn
  nltk
C++ (Frontend):
  Qt framework (QApplication, QProcess)
To install the libraries of C++ paste this command in terminal
  sudo apt install qtbase5-dev
TO compile main.cpp file, command
  g++ -fPIC main.cpp -o qt_app `pkg-config --cflags --libs Qt5Widgets`

Usage:
Clone the repository
Make sure you’re on a Linux system with Qt installed
Load qt_app and run it
Enter a tweet to analyze its sentiment

Notes
The dataset is from 2009, so modern slang or emoji handling is limited.
Model accuracy may vary on current tweets due to language evolution.
Enconder used ISO-8859-1
