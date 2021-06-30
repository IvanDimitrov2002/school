package main.java.com.shop;

import java.util.Map;

public class Order {
    private Integer id;
    private Integer customerId;
    private Address customerAddress;
    private Status status;
    private Double totalPrice;
    private Map<Product, Integer> products;
    private static Integer orderCount = 0;

    public Order(Integer customerId, Address customerAddress, Status status, Double totalPrice, Map<Product, Integer> products) {
        this.id = orderCount++;
        this.customerId = customerId;
        this.customerAddress = customerAddress;
        this.status = status;
        this.totalPrice = totalPrice;
        this.products = products;
    }

    @Override
    public int hashCode() {
        return id;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Order) {
            if(((Order) obj).getId() == id) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getCustomerId() {
        return customerId;
    }

    public void setCustomerId(Integer customerId) {
        this.customerId = customerId;
    }

    public Address getCustomerAddress() {
        return customerAddress;
    }

    public void setCustomerAddress(Address customerAddress) {
        this.customerAddress = customerAddress;
    }

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }

    public Double getTotalPrice() {
        return totalPrice;
    }

    public void setTotalPrice(Double totalPrice) {
        this.totalPrice = totalPrice;
    }

    public Map<Product, Integer> getProducts() {
        return products;
    }

    public void setProducts(Map<Product, Integer> products) {
        this.products = products;
    }

    public static Integer getOrderCount() {
        return orderCount;
    }

    public static void setOrderCount(Integer orderCount) {
        Order.orderCount = orderCount;
    }
}
