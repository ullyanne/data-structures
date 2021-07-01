#include <stdio.h>
#include <stdlib.h>

struct binaryTree
{
    int item;
    struct binaryTree* left;
    struct binaryTree* right;
};

struct binaryTree* create(int item)
{
    struct binaryTree* newBT = (struct binaryTree*) malloc(sizeof(struct binaryTree));
    newBT->item = item;

    newBT->left = NULL;
    newBT->right = NULL;

    return newBT;
}

struct binaryTree* add(struct binaryTree* bt, int item)
{
    if(bt == NULL)
        bt = create(item);
    else if(bt->item > item)
        bt->left = add(bt->left, item);
    else if(bt->item <= item)
        bt->right = add(bt->right, item);
    
    return bt;
}

void inOrder(struct binaryTree* bt)
{
    if(bt != NULL)
    {
        inOrder(bt->left);
        printf("%d ", bt->item);
        inOrder(bt->right);
    }
}

void preOrder(struct binaryTree* bt)
{
    if(bt != NULL)
    {
        printf("%d ", bt->item);
        preOrder(bt->left);
        preOrder(bt->right);
    }
}

void postOrder(struct binaryTree* bt)
{
    if(bt != NULL)
    {
        postOrder(bt->left);
        postOrder(bt->right);
        printf("%d ", bt->item);
    }
}

int main()
{
    struct binaryTree* root = NULL;
    
    return 0;
}