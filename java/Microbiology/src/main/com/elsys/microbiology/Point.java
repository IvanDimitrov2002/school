package main.com.elsys.microbiology;

public class Point {
   private Integer x;
   private Integer y;

    public Point(Integer x, Integer y) {
        this.x = x;
        this.y = y;
    }



    public Double distanceTo(Point point2) {
        return Math.sqrt(Math.pow(x - point2.x, 2) + Math.pow(y - point2.y, 2));
    }

    @Override
    public String toString() {
        return "Point{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

    public Integer getX() {
        return x;
    }

    public void setX(Integer x) {
        this.x = x;
    }

    public Integer getY() {
        return y;
    }

    public void setY(Integer y) {
        this.y = y;
    }
}
