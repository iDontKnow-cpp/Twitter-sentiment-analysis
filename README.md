# 🐦 Twitter Sentiment Analysis

A simple sentiment analysis application built using Python and C++, leveraging the **Sentiment140 dataset** to classify tweets as **Positive** or **Negative**.

---

## 📚 Overview

This project uses a Logistic Regression model trained on **1.6 million tweets** from the Sentiment140 dataset (collected in 2009 and encoded in `ISO-8859-1` due to the dataset's age).

---

## 🧠 Model Details

- **Algorithm Used:** Logistic Regression  
- **Language:** Python (model training and backend)  
- **Model Output Formats:**
  - `trained_model.sav`
  - `trained_model.pkl`

These files contain the serialized model and can be loaded for inference.

---

## 🧹 Preprocessing Techniques

Applied in both training and inference (within `Model.py`):

- Remove special characters and numbers
- Convert text to lowercase
- Remove stopwords (e.g., "the", "is", "and")
- Apply stemming using `PorterStemmer` (e.g., "running" → "run")

---

## 🖥 Application Frontend

- **Language:** C++
- **Framework:** Qt (GUI built with `QApplication`)
- **Communication:** `QProcess` for invoking the Python backend
- **Executable:** `qt_app`
- **Platform:** Linux-only (for now)

---

## ⚙️ How It Works

1. User enters a tweet into the Qt-based GUI.
2. `qt_app` passes the text to the Python backend via `QProcess`.
3. Backend applies the same preprocessing as the training phase.
4. Trained model classifies the tweet as Positive or Negative.
5. Result is displayed in the GUI.

---

## 📦 Requirements

### Python (Backend)

- `pandas`  
- `numpy`  
- `scikit-learn`  
- `nltk`

### C++ (Frontend)

- Qt Framework
  - `QApplication`
  - `QProcess`

📥 To install C++ Qt dependencies:

```bash
sudo apt install qtbase5-dev
