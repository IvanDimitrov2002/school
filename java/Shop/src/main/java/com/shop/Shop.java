package main.java.com.shop;

import java.util.*;

public class Shop {
    private Map<Product, Integer> availableProducts = new HashMap<Product, Integer>();
    private Country originCountry;
    private Set<Country> countries = new HashSet<Country>();
    private Set<Order> orders = new HashSet<Order>();
    private Set<RegisteredCustomer> registeredCustomers = new HashSet<RegisteredCustomer>();
    private Map<Product, Integer> activeCart = new HashMap<Product, Integer>();
    private Customer activeCustomer;

    public Shop(Map<Product, Integer> availableProducts, Country originCountry, Set<Country> countries, Set<Order> orders, Set<RegisteredCustomer> registeredCustomers, Map<Product, Integer> activeCart, Customer activeCustomer) {
        this.availableProducts = availableProducts;
        this.originCountry = originCountry;
        this.countries = countries;
        this.orders = orders;
        this.registeredCustomers = registeredCustomers;
        this.activeCart = activeCart;
        this.activeCustomer = activeCustomer;
    }

    public void registerCustomer(Customer newCustomer) throws CustomerCredentialsInvalid {
        if(newCustomer.getFirstName() == null || newCustomer.getFirstName().isBlank()){
            throw new CustomerCredentialsInvalid("First name");
        }
        if(newCustomer.getLastName() == null || newCustomer.getLastName().isBlank()){
            throw new CustomerCredentialsInvalid("Last name");
        }
        if(!newCustomer.getAddress().isValid()){
            throw new CustomerCredentialsInvalid("Address");
        }
        registeredCustomers.add((RegisteredCustomer) newCustomer);
    }

    public void addProduct(Product product, Integer amount) throws  ProductDetailsInvalid{
        if(product.getName() == null || product.getName().isBlank()){
            throw new ProductDetailsInvalid("Name");
        }
        if(product.getPrice() == null){
            throw new ProductDetailsInvalid("Price");
        }
        if(product.getCurrency() == null){
            throw  new ProductDetailsInvalid("Currency");
        }
        if(availableProducts.containsKey((product))){
            availableProducts.put(product, (availableProducts.get(product) + amount));
        } else {
            availableProducts.put(product, amount);
        }
    }

    public void removeProduct(Product product, Integer amount) throws ProductDoesNotExists, ProductQuantityInvalid{
        if(availableProducts.containsKey(product)){
            if(availableProducts.get(product) >= amount){
                availableProducts.put(product, (availableProducts.get(product) - amount));
            } else {
                throw new ProductQuantityInvalid();
            }
        } else {
            throw new ProductDoesNotExists();
        }
    }

    public void addProductToCard(Integer id, Integer amount) throws ProductDoesNotExists, ProductQuantityInvalid {
        for (Map.Entry<Product, Integer> entry : availableProducts.entrySet()) {
            if(entry.getKey().getId() == id){
                if(entry.getValue() >= amount){
                    activeCart.put(entry.getKey(), amount);
                    return;
                } else {
                    throw new ProductQuantityInvalid();
                }
            }
        }
        throw new ProductDoesNotExists();
    }

    public void checkoutCart() throws CartIsEmpty {
        if(activeCart.isEmpty()){
            throw new CartIsEmpty();
        } else {
            if(activeCustomer.getId() == null){
                activeCustomer = new Guest();
            }
            Double totalPrice = 0.0;
            for (Map.Entry<Product, Integer> entry : activeCart.entrySet()) {
                totalPrice += (entry.getValue() * entry.getKey().getPrice());
            }
            Order newOrder = new Order(activeCustomer.getId(), activeCustomer.getAddress(), Status.Open, totalPrice, activeCart);
            orders.add(newOrder);
        }
    }

    public void shipOrder(Integer id) throws OrderDoesNotExists {
        Iterator<Order> iterator = orders.iterator();
        while(iterator.hasNext()){
            Order currOrder = iterator.next();
            if(currOrder.getId() == id){
                if(countries.contains(currOrder.getCustomerAddress().getDeliveryCountry())){
                    currOrder.setStatus(Status.Shipped);
                } else {
                    currOrder.setStatus(Status.Failed);
                }
                return;
            }
        }
        throw new OrderDoesNotExists();
    }

    public void completeOrder(Integer id) throws OrderDoesNotExists {
        Iterator<Order> iterator = orders.iterator();
        while(iterator.hasNext()){
            Order currOrder = iterator.next();
            if(currOrder.getId() == id){
                currOrder.setStatus(Status.Completed);
                return;
            }
        }
        throw new OrderDoesNotExists();
    }

    public void failOrder(Integer id) throws OrderDoesNotExists {
        Iterator<Order> iterator = orders.iterator();
        while(iterator.hasNext()){
            Order currOrder = iterator.next();
            if(currOrder.getId() == id){
                currOrder.setStatus(Status.Failed);
                return;
            }
        }
        throw new OrderDoesNotExists();
    }

    public Map<Product, Integer> getAvailableProducts() {
        return availableProducts;
    }

    public void setAvailableProducts(Map<Product, Integer> availableProducts) {
        this.availableProducts = availableProducts;
    }

    public Country getOriginCountry() {
        return originCountry;
    }

    public void setOriginCountry(Country originCountry) {
        this.originCountry = originCountry;
    }

    public Set<Country> getCountries() {
        return countries;
    }

    public void setCountries(Set<Country> countries) {
        this.countries = countries;
    }

    public Set<Order> getOrders() {
        return orders;
    }

    public void setOrders(Set<Order> orders) {
        this.orders = orders;
    }

    public Set<RegisteredCustomer> getRegisteredCustomers() {
        return registeredCustomers;
    }

    public void setRegisteredCustomers(Set<RegisteredCustomer> registeredCustomers) {
        this.registeredCustomers = registeredCustomers;
    }

    public Map<Product, Integer> getActiveCart() {
        return activeCart;
    }

    public void setActiveCart(Map<Product, Integer> activeCart) {
        this.activeCart = activeCart;
    }

    public Customer getActiveCustomer() {
        return activeCustomer;
    }

    public void setActiveCustomer(Customer activeCustomer) {
        this.activeCustomer = activeCustomer;
    }
}
