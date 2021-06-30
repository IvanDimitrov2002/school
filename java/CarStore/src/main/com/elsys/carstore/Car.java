package main.com.elsys.carstore;

public abstract class Car implements Comparable<Car> {
    protected static int sofiaNumber = 1000;
    protected static int burgasNumber = 1000;
    protected static int varnaNumber = 1000;
    protected static int vratsaNumber = 1000;
    protected static int plovdivNumber = 1000;
    protected static int vidinNumber = 1000;
    protected static int gabrovoNumber = 1000;
    protected static int ruseNumber = 1000;

    protected Model model;
    protected int year;
    protected int price;
    protected EngineType engineType;
    protected String registrationNumber;
    protected Region region;

    @Override
    public int compareTo(Car car) {
        int modelCompare = model.compareTo(car.getModel());
        if(modelCompare != 0) return modelCompare;

        return Integer.compare(year, car.getYear());
    }

    /**
     * Returns the number by the selected region then increments the variable.
     */
    public static int getNumber(Region region){
        switch(region){
            case SOFIA:
                return sofiaNumber++;

            case BURGAS:
                return burgasNumber++;

            case VARNA:
                return varnaNumber++;

            case PLOVDIV:
                return plovdivNumber++;

            case RUSE:
                return ruseNumber++;

            case GABROVO:
                return gabrovoNumber++;

            case VIDIN:
                return vidinNumber++;

            case VRATSA:
                return vratsaNumber++;
        }
        return -1;
    }

    /**
     * Returns the model of the car.
     */
    public Model getModel(){
        return model;
    }

    /**
     * Returns the year of manufacture of the car.
     */
    public int getYear(){
        return year;
    }

    /**
     * Returns the price of the car.
     */
    public int getPrice(){
        return price;
    }

    /**
     * Returns the engine type of the car.
     */
    public EngineType getEngineType(){
        return engineType;
    }

    /**
     * Returns the unique registration number of the car.
     */
    public String getRegistrationNumber(){
        return registrationNumber;
    }

    /**
     * Returns the region of the car.
     */
    public Region getRegion(){
        return region;
    }

    /**
     * Sets the model of the car.
     */
    public void setModel(Model model) {
        this.model = model;
    }

    /**
     * Sets the year of manufacture of the car.
     */
    public void setYear(int year) {
        this.year = year;
    }

    /**
     * Sets the price of the car.
     */
    public void setPrice(int price) {
        this.price = price;
    }

    /**
     * Sets the engine type of the car.
     */
    public void setEngineType(EngineType engineType) {
        this.engineType = engineType;
    }

    /**
     * Sets the unique registration number of the car.
     */
    public void setRegistrationNumber(String registrationNumber) {
        this.registrationNumber = registrationNumber;
    }

    /**
     * Sets the region of the car.
     */
    public void setRegion(Region region){
        this.region = region;
    }
}