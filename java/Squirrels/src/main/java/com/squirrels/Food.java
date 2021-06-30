package main.java.com.squirrels;

public abstract class Food implements IExpirable{
    protected Double quality;
    protected Double quantity;

    public Food(Double quantity, Double quality) {
        this.quality = quality;
        this.quantity = quantity;
    }

    public Double getFoodScore(){
        return quality * quantity;
    }

    public Double getQuality() {
        return quality;
    }

    public void setQuality(Double quality) {
        this.quality = quality;
    }

    public Double getQuantity() {
        return quantity;
    }

    public void setQuantity(Double quantity) {
        this.quantity = quantity;
    }
}
