package main.com.elsys.microbiology;

import java.util.ArrayList;

public class Food  {
    private Point position;
    private Integer quantity;

    public Food(Point position, Integer quantity) {
        this.position = position;
        this.quantity = quantity;
    }

    @Override
    public String toString() {
        return "Food{" +
                "position=" + position +
                ", quantity=" + quantity +
                '}';
    }

    public Point getPosition() {
        return position;
    }

    public void setPosition(Point position) {
        this.position = position;
    }

    public Integer getQuantity() {
        return quantity;
    }

    public void setQuantity(Integer quantity) {
        this.quantity = quantity;
    }
}
