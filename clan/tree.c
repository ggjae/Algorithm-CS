#include <stdio.h>
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;
int main(){
    TreeNode n1 = { 1, NULL, NULL };
    TreeNode n2 = { 4, NULL, NULL };
    TreeNode n3 = { 'a', &n1, &n2 };
    TreeNode n4 = { 16, NULL, NULL };
    TreeNode n5 = { 25, NULL, NULL };
    TreeNode n6 = { 'a', &n4, &n5 };
    TreeNode n7 = { 'a', &n3, &n6 };
    TreeNode *exp = &n7;
    return 0;
    
}