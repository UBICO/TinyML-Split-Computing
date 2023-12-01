import numpy as np
from PIL import Image, ImageDraw, ImageFont

class ModelDataGenerator:
    def __init__(self, image_size=40, num_images=2, dataset_path=''):
        self.image_size = image_size
        self.num_images = num_images
        self.images = None
        self.labels = None
        self.dataset_path = dataset_path

    def generate_dataset(self):
        # Generate random images with values between 1 and 10
        rand_list = np.random.randint(0, 2, self.num_images)
        
        # Create labels: 1 if the image contains the number 1, else 0
        self.labels = np.array([[1] if rand_num == 1 else [0] for rand_num in rand_list])

        image_paths = []
        for i in range(len(self.labels)):
            label_text = str(self.labels[i][0])
            image_path = f'image_{i}.png'
            self.create_save_image(image_path, label_text)
            image_paths.append(image_path)

        return image_paths, self.labels


    def create_save_image(self, image_path, text):
        # Create a blank image
        image = Image.new('RGB', (self.image_size, self.image_size), color = 'white')
        draw = ImageDraw.Draw(image)

        # Use a basic font (you can customize the font if needed)
        font = ImageFont.load_default()

        # Get the text size bounding box
        textbbox = draw.textbbox((0, 0), text, font)

        # Center the text on the image
        x = (image.width - textbbox[2]) / 2
        y = (image.height - textbbox[3]) / 2

        # Draw the text on the image
        draw.text((x, y), text, fill='black', font=font)

        # Save the image
        image.save(f'{self.dataset_path}/{image_path}')

