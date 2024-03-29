from PIL import Image
import PIL.ImageOps

input = input("Program:")

image = Image.open(input)
if image.mode == 'RGBA':
    r,g,b,a = image.split()
    rgb_image = Image.merge('RGB', (r,g,b))

    inverted_image = PIL.ImageOps.invert(rgb_image)

    r2, g2, b2 = inverted_image.split()

    final_transparent_image = Image.merge('RGBA', (r2, g2, b2, a))

    final_transparent_image.save('new_.png')

else:
    inverted_image = PIL.ImageOps.invert(image)
    inverted_image.save('new_.png')