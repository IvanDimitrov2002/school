#ifndef BINARYTREE_H
#define BINARYTREE_H


class Binarytree{
    public:
        int data;
        Binarytree *left, *right;

        Binarytree(){};

        Binarytree(int data);

        Binarytree(const Binarytree& binarytree);

        ~Binarytree();

        void printTree();

        void insert(int data);
};

#endif