package main.com.elsys.Angryman;

import java.awt.*;
import java.awt.image.BufferedImage;
import java.util.HashSet;

public class Tracing {
    public void GetBoundary(BufferedImage image)
    {
        for (int j = 1; j < image.getHeight(); j++){
            for (int i = 1; i < image.getWidth(); i++){
                Color pixel = new Color(image.getRGB(i, j));
                if (pixel.getRed() == 255 && pixel.getGreen() == 255 && pixel.getBlue() == 255){
                    SquareTrace(new Point(i, j), image);
                }
            }
        }
    }

    public void SquareTrace(Point start, BufferedImage image)
    {
        // The first pixel you encounter is a white one by definition, so we go left.
        // Our initial direction was going from left to right, hence (1, 0)
        Point nextStep = GoLeft(new Point(1, 0));
        Point next = Point.sumPoints(start, nextStep);
        for(int i = 0; i < 2; i++)
        {
            // We found a black cell, so we go right and don't add this cell to our HashSet
            Color pixel = new Color(image.getRGB(next.x, next.y));
            if (pixel.getRed() == 0 && pixel.getGreen() == 0 && pixel.getBlue() == 0)
            {
                image.setRGB(next.x, next.y, new Color(255, 0, 0).getRGB());
                next = Point.subPoints(next, nextStep);
                nextStep = GoRight(nextStep);
                next = Point.sumPoints(next, nextStep);
            }
            // Alternatively we found a white cell, we do add this to our HashSet
            else
            {
                nextStep = GoLeft(nextStep);
                next = Point.sumPoints(next, nextStep);
            }
        }
    }

    private Point GoLeft(Point p){
        return new Point(p.y, -p.x);
    }
    private Point GoRight(Point p){
        return new Point(-p.y, p.x);
    }
}
