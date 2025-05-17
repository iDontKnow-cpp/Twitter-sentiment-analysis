import os
import warnings
import sys
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
warnings.filterwarnings("ignore")
sys.stderr = open(os.devnull, 'w')

import cv2
import tensorflow as tf
import numpy as np # Import numpy for array manipulation

# Define class labels if they're not already defined
class_labels = ['Angry', 'Disgust', 'Fear', 'Happy', 'Neutral', 'Sad', 'Surprise']

print("Args:", sys.argv)
print("Python script started")

def main(path):
  model = tf.keras.models.load_model('facial_expression.h5')
  X_new = preprocessing(path)

  # Check if preprocessing was successful (face detected)
  if X_new is not None:
      # Reshape the image to add a channel dimension if necessary
    if len(X_new.shape) == 2:  # Check if grayscale
      X_new = X_new.reshape(X_new.shape[0], X_new.shape[1], 1)
      # Expand dimensions to create a batch of size 1
    X_new = np.expand_dims(X_new, axis=0)
    prediction = model.predict(X_new)

      # Get the index of the predicted class
    predicted_class_index = np.argmax(prediction)

      # Get the corresponding class label
    predicted_class_label = class_labels[predicted_class_index]

    print("Predicted Emotion:", predicted_class_label, flush=True)

def preprocessing(path):
  image = cv2.imread(path)

# Load Haar Cascade for face detection
  face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

  gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Detect faces
  faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5)

# Check if at least one face was found
  if len(faces) == 0:
    print("No face detected.")
    return None # Return None to indicate failure to detect a face
  else:
    for (x, y, w, h) in faces:
        # Crop the face from the grayscale image
      face_crop = gray[y:y+h, x:x+w] # Use gray instead of image

  imgSize = (64,64)
  img = cv2.resize(face_crop,imgSize)
  return img

if __name__ == '__main__':
  if len(sys.argv) < 2:
    print("No image path provided.")
  else:
    main(sys.argv[1])
