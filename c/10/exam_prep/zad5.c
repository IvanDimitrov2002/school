#include <stdio.h>
#include <string.h>

struct ingredient_t{
    char name[50];
    float energy;
    int has_meat;
};

struct dish_t{
    char name[50];
    struct ingredient_t ingredients[100];
    int number_of_ingredients;
};

struct dish_t dish_maker(struct dish_t dish, struct ingredient_t ingredients[100], int number_of_ingredients){
    dish.number_of_ingredients=number_of_ingredients;
    for(int i=0;i<number_of_ingredients;i++){
        dish.ingredients[i]=ingredients[i];
    }
    return dish;
}

struct dish_t add_ingredient(struct dish_t dish, struct ingredient_t ingredient){
    dish.ingredients[dish.number_of_ingredients]=ingredient;
    dish.number_of_ingredients++;
    return dish;
}

void print_dish(struct dish_t dish){
    float energy_sum=0;
    printf("Dish name: %s\n", dish.name);
    for(int i=0;i<dish.number_of_ingredients;i++){
        printf("Ingredient name: %s\n", dish.ingredients[i].name);
        energy_sum+=dish.ingredients[i].energy;
        printf("Meat content: %d\n", dish.ingredients[i].has_meat);
    }
    printf("Total energy of the dish: %.2f\n", energy_sum);
    printf("Total number of ingredients: %d\n", dish.number_of_ingredients);
}

int is_vegeterian(struct dish_t dishes[100], float max_energy){
    int number_of_dishes;
    printf("Enter the number of dishes: \n");
    scanf("%d", &number_of_dishes);
    for(int k=0;k<2;k++){
        float energy_sum=0;
        int has_meat=0;
        for(int i=0;i<dishes[k].number_of_ingredients;i++){
            energy_sum+=dishes[k].ingredients[i].energy;
            if(dishes[k].ingredients[i].has_meat==1){
                has_meat=1;
            }
        }
        if(energy_sum>max_energy || has_meat==1) printf("Dish %d is not vegeterian\n", k+1);
    }
    return 0;
}

int main(){
    struct dish_t dishes[3];
    strcpy(dishes[0].name, "Chicken");
    struct ingredient_t ingredients[5];
    strcpy(ingredients[0].name, "Salt");
    strcpy(ingredients[1].name, "Onion");
    strcpy(ingredients[2].name, "Rice");
    ingredients[0].energy=5;
    ingredients[1].energy=10;
    ingredients[2].energy=15;
    ingredients[0].has_meat=0;
    ingredients[1].has_meat=0;
    ingredients[2].has_meat=0;
    dishes[0]=dish_maker(dishes[0], ingredients, 3);
    strcpy(dishes[1].name, "Pork");
    struct ingredient_t ingredients_two[5];
    strcpy(ingredients_two[0].name, "Pepper");
    strcpy(ingredients_two[1].name, "Potatoes");
    strcpy(ingredients_two[2].name, "Carrots");
    ingredients_two[0].energy=5;
    ingredients_two[1].energy=10;
    ingredients_two[2].energy=15;
    ingredients_two[0].has_meat=0;
    ingredients_two[1].has_meat=0;
    ingredients_two[2].has_meat=1;
    dishes[1]=dish_maker(dishes[1], ingredients_two, 3);
    printf("%d\n", is_vegeterian(dishes, 100));
    return 0;
}