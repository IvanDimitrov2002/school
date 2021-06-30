#include "binarytree.h"
#include <iostream>

int main(){
    Binarytree *tree = new Binarytree(1);
    tree->insert(2);
    tree->printTree();
    return 0;
}