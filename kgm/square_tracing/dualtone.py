# import numpy as np
# import cv2

# img = cv2.imread('input.png')
# gr = cv2.cvtColor(img, cv2.IMREAD_GRAYSCALE)
# edge = cv2.Canny(gr, 300, 200)
# cont, hierarchy = cv2.findContours(edge, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
# cv2.drawContours(img, cont, -1, (255, 0, 0), 1, hierarchy=hierarchy)
# cv2.imwrite("output.png", img)


from PIL import Image, ImageDraw

# Load image:
input_image = Image.open("input.png")
input_pixels = input_image.load()

# Create output image
output_image = Image.new("RGB", input_image.size)
draw = ImageDraw.Draw(output_image)

# Compute convolution between intensity and kernels
for x in range(input_image.width):
    for y in range(input_image.height):
        pixel = input_pixels[x, y]
        if(pixel != (0, 0, 0) and pixel != (255, 255, 255)):
            draw.point((x, y), (0, 0, 0))
        else:
            draw.point((x, y), (int(pixel[0]), int(pixel[1]), int(pixel[2])))

output_image.save("output.png")
