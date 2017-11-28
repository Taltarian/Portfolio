from tkinter import *
import random
import math
# Graphics commands.

def draw_line(start, end, color, canvas):
    """This function draws a line between the start and end point. The line
    will be of the specified color on the canvas."""
    return canvas.create_line(start[0], start[1], end[0],
    end[1], fill = color, width = 3)

def draw_star(center, npoints, color, canvas):
    """This function draws a star with npoints centered at a certain point
    on the canvas."""
    radius = random.randint(50,100)
    coordinates = []
    for i in range(npoints):
        theta = i * (2 * math.pi) / npoints
        coordinates.append((center[0] + radius * math.sin(theta),
        center[1] - radius * math.cos(theta)))
    for i, e in enumerate(coordinates):
        nextpoint = int(i + (npoints - 1) / 2)
        nextpoint %= npoints
        lines.append(draw_line(e, coordinates[nextpoint], color, canvas))

def random_color():
    """This function returns a random color as a hex string."""
    return "#" + format(random.randint(0, 0xffffff), '06x')
# Event handlers.

def key_handler(event):
    '''Handle key presses.'''
    global color
    global N
    global lines
    event = event.keysym
    if event == 'q':
        quit()
    elif event == "plus":
        N += 2
    elif event == "minus":
        if N != 5:
            N -= 2
    elif event == 'c':
        color = random_color()
    elif event == 'x':
        for i in lines:
            canvas.delete(i)
        lines = []
def button_handler(event):
    '''Handle left mouse button click events.'''
    draw_star((event.x, event.y), N, color, canvas)


if __name__ == '__main__':
    color = random_color()
    lines = []
    N = 5
    root = Tk()
    root.geometry('800x800')
    canvas = Canvas(root, width=800, height=800)
    canvas.pack()

    # Bind events to handlers.
    root.bind('<Key>', key_handler)
    canvas.bind('<Button-1>', button_handler)

    # Start it up.
    root.mainloop()
