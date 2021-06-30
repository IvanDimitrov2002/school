package main.java.com.shop;

public class Product {
    private Integer id;
    private String name;
    private Double price;
    private Currency currency = null;
    static private Integer productCount = 0;

    public Product(String name, Double price, Currency currency) {
        this.id = productCount++;
        this.name = name;
        this.price = price;
        this.currency = currency;
    }

    public Product(Integer id, String name, Double price, Currency currency) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.currency = currency;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Double getPrice() {
        return price;
    }

    public void setPrice(Double price) {
        this.price = price;
    }

    public Currency getCurrency() {
        return currency;
    }

    public void setCurrency(Currency currency) {
        this.currency = currency;
    }

    public static Integer getProductCount() {
        return productCount;
    }

    public static void setProductCount(Integer productCount) {
        Product.productCount = productCount;
    }
}
