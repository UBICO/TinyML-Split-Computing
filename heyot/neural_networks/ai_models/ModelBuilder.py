import tensorflow as tf
from tensorflow.keras import layers, models
import os
from sklearn.model_selection import train_test_split
import numpy as np 

class ModelBuilder:
    def __init__(self, image_size=10, num_classes=2, image_paths=[], labels=[], dataset_path=''):
        self.image_size = image_size
        self.num_classes = num_classes
        self.image_paths = image_paths
        self.labels = labels
        self.model = self.build_model()
        self.dataset_path = dataset_path

    def build_model(self):
    
        model = models.Sequential()
        model.add(layers.Conv2D(32, (3, 3), activation='relu', input_shape=(10, 10, 3), name="layer_0"))
        model.add(layers.MaxPooling2D((2, 2), name="layer_1"))
        model.add(layers.Flatten(name="layer_2"))
        model.add(layers.Dense(64, activation='relu', name="layer_3"))
        model.add(layers.Dense(self.num_classes, activation='sigmoid', name="layer_4"))

        model.compile(optimizer='adam',
                    loss='binary_crossentropy',
                    metrics=['accuracy'])
        return model

    def prepare_data(self):
        images = []
        for path in self.image_paths:
            img = tf.keras.preprocessing.image.load_img(
                os.path.join(self.dataset_path, path), target_size=(self.image_size, self.image_size)
            )
            img_array = tf.keras.preprocessing.image.img_to_array(img)
            img_array /= 255.0
            images.append(img_array)

        X_train, X_test, y_train, y_test = train_test_split(images, self.labels, test_size=0.2, random_state=42)

        return np.array(X_train), np.array(X_test), np.array(y_train), np.array(y_test)

    def train_model(self, epochs=10):
        X_train, X_test, y_train, y_test = self.prepare_data()
        self.model.fit(X_train, y_train, epochs=epochs, validation_data=(X_test, y_test))

    def evaluate_model(self):
        X_train, X_test, y_train, y_test = self.prepare_data()
        loss, accuracy = self.model.evaluate(X_test, y_test)
        print(f"Test Loss: {loss:.4f}, Test Accuracy: {accuracy:.4f}")

    def predict(self, image_path):
        img = tf.keras.preprocessing.image.load_img(
            image_path, target_size=(self.image_size, self.image_size)
        )
        img_array = tf.keras.preprocessing.image.img_to_array(img)
        img_array = np.expand_dims(img_array, axis=0)
        img_array /= 255.0
        prediction = self.model.predict(img_array)
        return prediction
    
    def save_model_as_h5(self, model_name='saved_model'):
        # Ensure the directory for the file exists
        os.makedirs(os.path.dirname(f'models/{model_name}'), exist_ok=True)
        # Save the model to an HDF5 file
        self.model.save(f'models/{model_name}/{model_name}.h5')