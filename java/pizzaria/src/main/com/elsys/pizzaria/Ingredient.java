package main.com.elsys.pizzaria;

public class Ingredient {
    private String name;
    private IngredientType ingredientType;
    private Double time;

    public Ingredient(String name, String type) {
        this.name = name;
        switch(type.toLowerCase()) {
            case "dough":
                this.ingredientType = IngredientType.DOUGH;
                this.time = 2.0;
                break;

            case "sauce":
                this.ingredientType = IngredientType.SAUCE;
                this.time = 1.0;
                break;

            case "vegetable":
                this.ingredientType = IngredientType.VEGETABLE;
                this.time = 0.5;
                break;

            case "cheese":
                this.ingredientType = IngredientType.CHEESE;
                this.time = 1.0;
                break;

            case "meat":
                this.ingredientType = IngredientType.MEAT;
                this.time = 1.5;
                break;

            default:
                this.ingredientType = null;
                this.time = null;
                break;
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public IngredientType getIngredientType() {
        return ingredientType;
    }

    public void setIngredientType(IngredientType ingredientType) {
        this.ingredientType = ingredientType;
    }

    public Double getTime() {
        return time;
    }

    public void setTime(Double time) {
        this.time = time;
    }
}
