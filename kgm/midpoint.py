def midPoint(x1, y1, x2, y2):
    # calculate dx & dy
    dx = x2 - x1
    dy = y2 - y1

    # initial value of decision parameter d
    d = dy - (dx / 2)
    x = x1
    y = y1

    # Plot initial given point
    print(x, ",", y, "\n")
    # iterate through value of X
    while (x < x2):
        x = x + 1
        # E or East is chosen
        if(d < 0):
            d = d + dy

        # NE or North East is chosen
        else:
            d = d + (dy - dx)
            y = y+1

        # Plot intermediate points
        print(x, ",", y, "\n")


if __name__ == '__main__':
    x1 = 2
    y1 = 2
    x2 = 8
    y2 = 5
    midPoint(x1, y1, x2, y2)
