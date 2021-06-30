package main.java.com.shop;

public class Address {
    private Country deliveryCountry = null;
    private String city;
    private String street;
    private Integer streetNumber;
    private Integer apartment;

    public Address(Country deliveryCountry, String city, String street, Integer streetNumber, Integer apartment) {
        this.deliveryCountry = deliveryCountry;
        this.city = city;
        this.street = street;
        this.streetNumber = streetNumber;
        this.apartment = apartment;
    }

    public Boolean isValid(){
        if(deliveryCountry == null){
            return false;
        }
        if(city == null || city.isBlank()){
            return false;
        }
        if(street == null || street.isBlank()){
            return false;
        }
        if(streetNumber == null){
            return false;
        }
        if(apartment == null){
            return false;
        }
        return true;
    }

    public Country getDeliveryCountry() {
        return deliveryCountry;
    }

    public void setDeliveryCountry(Country deliveryCountry) {
        this.deliveryCountry = deliveryCountry;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getStreet() {
        return street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public Integer getStreetNumber() {
        return streetNumber;
    }

    public void setStreetNumber(Integer streetNumber) {
        this.streetNumber = streetNumber;
    }

    public Integer getApartment() {
        return apartment;
    }

    public void setApartment(Integer apartment) {
        this.apartment = apartment;
    }
}
