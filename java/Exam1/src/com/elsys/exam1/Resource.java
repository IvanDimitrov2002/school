package com.elsys.exam1;

public class Resource {
    private Position position;
    private Integer quantity;

    public Resource(){};

    public Resource(Position position, Integer quantity) {
        this.position = position;
        this.quantity = quantity;
    }

    public Position getPosition() {
        return position;
    }

    public void setPosition(Position position) {
        this.position = position;
    }

    public Integer getQuantity() {
        return quantity;
    }

    public void setQuantity(Integer quantity) {
        this.quantity = quantity;
    }
}
