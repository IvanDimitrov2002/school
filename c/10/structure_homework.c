#include <stdio.h>
#include <string.h>

struct bot_t {
    char address[100];
    char data[2][20];
};

struct pizza_t {
    char pizza_variant[10][50];
};

void pizza_order(struct pizza_t pizza, int number_of_menu_items){
    struct bot_t bot;
    int i, number_of_pizzas, ordered_pizza[5];
    char stop;
    do {
        printf("Welcome to our pizza delivery site!\nTo be sure that everything is OK you have to enter your delivery details.\n");
        printf("Address: \n");
        scanf(" %[^\n]", bot.address);
        printf("How many pizzas do you want to order?: ");
        scanf("%d", &number_of_pizzas);
        printf("Select the numbers of the pizzas you want to order.\n");
        for(i=0;i<number_of_menu_items;i++){
            printf("%d %s\n", i+1, pizza.pizza_variant[i]);
        }
        for(i=0;i<number_of_pizzas;i++){
            scanf("%d", &ordered_pizza[i]);
        }
        printf("Please enter your name and mobile number: \n");
        scanf(" %[^\n]", bot.data[0]); scanf(" %[^\n]", bot.data[1]);
        printf("\nThank you!\n\nThese are the details about your order:\n");
        puts(bot.address);
        for(i=0;i<number_of_pizzas;i++){
            printf("%s\n", pizza.pizza_variant[ordered_pizza[i]-1]);
        }
        puts(bot.data[0]); puts(bot.data[1]);
        printf("Do you want to continue? (Y/n): ");
        scanf(" %c", &stop);
    } while(stop!='Y' && stop!='y');
}

int main() {
    struct pizza_t pizza;
    int number_of_menu_items = 3;
    strcpy(pizza.pizza_variant[0], "Пеперони");        
    strcpy(pizza.pizza_variant[1], "Капричоза");
    strcpy(pizza.pizza_variant[2], "Маргарита");
    pizza_order(pizza, number_of_menu_items);
    return 0;
}