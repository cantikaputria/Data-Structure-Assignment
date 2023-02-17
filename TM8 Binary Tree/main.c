#include "header.h"

int main ()
{
    tree T;
    char huruf;

    //membuat tree, A
    scanf(" %c", &huruf);
    makeTree(huruf, &T);

    //huruf B
    scanf(" %c", &huruf);
    addLeft(huruf, T.root);

    //huruf C
    scanf(" %c", &huruf);
    addRight(huruf, T.root);

    //huruf D
    scanf(" %c", &huruf);
    addLeft(huruf, T.root->right);

    //huruf E
    scanf(" %c", &huruf);
    addRight(huruf, T.root->left);

    //huruf F
    scanf(" %c", &huruf);
    addRight(huruf, T.root->right);

    //huruf G
    scanf(" %c", &huruf);
    addLeft(huruf, T.root->left->right);

    //huruf H
    scanf(" %c", &huruf);
    addRight(huruf, T.root->right->left);

    //huruf I
    scanf(" %c", &huruf);
    addRight(huruf, T.root->left->right);

    //huruf J
    scanf(" %c", &huruf);
    addRight(huruf, T.root->right->right);

    //huruf K
    scanf(" %c", &huruf);
    addLeft(huruf, T.root->right->right);

    //huruf L
    scanf(" %c", &huruf);
    addLeft(huruf, T.root->left->right->left);

    //huruf M
    scanf(" %c", &huruf);
    addLeft(huruf, T.root->right->left->right);

    //huruf N
    scanf(" %c", &huruf);
    addRight(huruf, T.root->right->left->right);

    first = 1;
    printf("Pre Order:\n");
	printTreePreOrder(T.root);
    delLeft(T.root->left->right->left);

    first = 1;
    printf("\nIn Order:\n");
	printTreeInOrder(T.root);
    delRight(T.root->right->right);

    first = 1;
    printf("\nPost Order:\n");
	printTreePostOrder(T.root);
    printf("\n");

    return 0;
}