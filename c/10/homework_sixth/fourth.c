#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct product_t{
    char name[255];
    float quality;
    int quantity;
};

struct factory_t{
    char name[255];
    struct product_t product;
};

struct warehouse_t{
    int number_of_sections;
    int max_production;
    struct product_t *products;
};

struct product_t* create_products(int number_of_factories, struct factory_t factories[number_of_factories]){
    struct product_t *products = (struct product_t*)malloc(sizeof(struct product_t)*number_of_factories);
    for(int i=0;i<number_of_factories;i++){
        strcpy(products[i].name, factories[i].product.name);
        products[i].quality=factories[i].product.quality;
        products[i].quantity=factories[i].product.quantity;
    }
    return products;
}
 
void store_products(int number_of_factories, struct product_t *products, struct warehouse_t *warehouse){
    for(int i=0;i<number_of_factories;i++){
        for(int j=0;j<warehouse->number_of_sections && products[i].quantity>0;j++){
            if(strcmp(products[i].name,warehouse->products[j].name)==0 && products[i].quality==warehouse->products[j].quality){
                if(warehouse->products[j].quantity+products[i].quantity>warehouse->max_production){
                    products[i].quantity=products[i].quantity-(warehouse->max_production - warehouse->products[j].quantity);
                    warehouse->products[j].quantity=warehouse->max_production;
                }
                else{
                    warehouse->products[j].quantity+=products[i].quantity;
                    products[i].quantity=0;
                }
            }  
        }
        for(int j=0;j<warehouse->number_of_sections && products[i].quantity>0;j++){
            if(strcmp(warehouse->products[j].name, "<empty>")==0){
                strcpy(warehouse->products[j].name, products[i].name);
                warehouse->products[j].quality=products[i].quality;
                if(products[i].quantity>warehouse->max_production){
                    products[i].quantity=products[i].quantity-warehouse->max_production;
                    warehouse->products[j].quantity=warehouse->max_production;
                }
                else{
                    warehouse->products[j].quantity+=products[i].quantity;
                    products[i].quantity=0;
                }
            }    
        }
        if(products[i].quantity>0)
            printf("There isn't any room for the remaining %d %s\n", products[i].quantity, products[i].name);
    }
    for(int i=0;i<warehouse->number_of_sections;i++)
        printf("%d - %d %s\n", i+1, warehouse->products[i].quantity, warehouse->products[i].name);
}

void create_and_store(int number_of_factories, struct factory_t factories[number_of_factories], struct warehouse_t *warehouse){
    struct product_t *products = create_products(number_of_factories, factories);
    store_products(number_of_factories, products, warehouse);
    free(products);
}

int main(int argc, char* argv[]){
    struct warehouse_t warehouse;
    warehouse.number_of_sections=atoi(argv[2]);
    warehouse.max_production=atoi(argv[3]);
    warehouse.products = (struct product_t*)malloc(sizeof(struct product_t) * warehouse.number_of_sections);
    for(int i=0;i<warehouse.number_of_sections;i++){
        strcpy(warehouse.products[i].name, "<empty>");
        warehouse.products[i].quality=0;
        warehouse.products[i].quantity=0;
    }
    int number_of_factories=atoi(argv[1]);
    struct factory_t factories[number_of_factories];
    for(int i=0;i<number_of_factories;i++){
        printf("Enter factory %d: ", i+1);
        scanf(" %[^,\n], %[^,\n],%f,%d", factories[i].name, factories[i].product.name, &factories[i].product.quality, &factories[i].product.quantity);
    }
    for(int i=0;i<atoi(argv[4]);i++){
        printf("--Iteration %d--\n", i+1);
        for(int j=0;j<number_of_factories;j++){
            printf("%s produced %d %s\n", factories[j].name, factories[j].product.quantity, factories[j].product.name);
        }
        printf("Warehouse:\n");
        create_and_store(number_of_factories, factories, &warehouse);
    }
    free(warehouse.products);
    return 0;
}