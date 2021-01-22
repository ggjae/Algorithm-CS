#include <stdio.h>
#include <stdlib.h>
typedef struct _treenode{
    int data;
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode* makeBtree(int data){
    treenode* newnode = (treenode*)malloc(sizeof(treenode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void postordertraverse(treenode *tree){
    if (tree == NULL) return;
    postordertraverse(&(tree->left));
    postordertraverse(&(tree->right));
    printf("%d\n",tree->data);
}
treenode* updatetree(treenode *tree, int data){
    if(tree == NULL){
        tree = makeBtree(data);
        return tree;
    } else if(data < tree->data){
        tree->left = updatetree(tree->left, data);
    } else if(data > tree->data){
        tree->right = updatetree(tree->right, data);
    }
    return tree;
}
int main(){
    int n;
    treenode * tree = NULL;
    while(scanf("%d", &n) != EOF){
        tree = updatetree(tree, n);
    }
    postordertraverse(tree);
    return 0;
}