from PIL import Image, ImageDraw


def go_left(x, y):
    return [y, -x]


def go_right(x, y):
    return [-y, x]


input_image = Image.open("input.png")
input_pixels = input_image.load()

output_image = input_image.copy()
draw = ImageDraw.Draw(output_image)

for j in range(1, input_image.height):
    for i in range(1, input_image.width):
        pixel = input_pixels[i, j]
        if pixel == (255, 255, 255):
            next_step = go_left(1, 0)
            next = [i + next_step[0], j + next_step[1]]
            while next != [i, j]:
                curr_pixel = input_pixels[next[0], next[1]]
                if curr_pixel == (0, 0, 0):
                    draw.point((next[0], next[1]), (255, 0, 0))
                    next = [next[0] - next_step[0], next[1] - next_step[1]]
                    next_step = go_right(next_step[0], next_step[1])
                    next = [next[0] + next_step[0], next[1] + next_step[1]]
                else:
                    next_step = go_left(next_step[0], next_step[1])
                    next = [next[0] + next_step[0], next[1] + next_step[1]]

output_image.save("output.png")
