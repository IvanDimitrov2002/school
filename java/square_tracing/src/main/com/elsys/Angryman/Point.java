package main.com.elsys.Angryman;

public class Point {
    public int x;
    public int y;

    public Point(int x, int y){
        this.x = x;
        this.y = y;
    }

    public static Point sumPoints(Point first, Point second){
        return new Point(first.x + second.x, first.y + second.y);
    }

    public static Point subPoints(Point first, Point second){
        return new Point(first.x - second.x, first.y - second.y);
    }

    public boolean equals(Point p){
        return this.x == p.x && this.y == p.y;
    }
}
