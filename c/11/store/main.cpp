#include "store.h"
#include "product.h"

int main(){
    Store store;
    Product bread = Product("Bread", "Simid", 1.4, "04892389489", "Tasty bread :)");
    store.addToStorage(bread);
    store.printProducts();
    return 0;
}