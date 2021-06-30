#include "binarytree.h"
#include <iostream>

Binarytree::Binarytree(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

Binarytree::Binarytree(const Binarytree& binarytree){
    this->data = binarytree.data;
    this->left = binarytree.left;
    this->right = binarytree.right;
}

Binarytree::~Binarytree(){
    
}

void Binarytree::printTree(){
    if(this == nullptr) return;
    this->left->printTree(); 
    std::cout << " " << this->data;
    this->right->printTree();
}

void Binarytree::insert(int data){
    if(data > this->data){
        this->right = new Binarytree(data);
        return;
    }
    this->left = new Binarytree(data);
}
