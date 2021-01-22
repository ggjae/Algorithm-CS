#include <stdio.h> 
#include <stdlib.h> 

typedef struct node 
{ 
     char data; 
     struct node* left; 
     struct node* right; 
}node; 
  
node* createnode(char data) 
{ 
     node* newnode = (node*) malloc(sizeof(node)); 
     newnode->data = data; 
     newnode->left = NULL; 
     newnode->right = NULL; 
  
     return newnode; 
} 
  
/* Given a binary tree, print its nodes according to the 
  "bottom-up" postorder traversal. */
void printPostorder(node* node) 
{ 
     if (node == NULL) 
        return; 
  
     // first recur on left subtree 
     printPostorder(node->left); 
  
     // then recur on right subtree 
     printPostorder(node->right); 
  
     // now deal with the node 
     printf("%c", node->data); 
} 
  
/* Given a binary tree, print its nodes in inorder*/
void printInorder(node* node) 
{ 
     if (node == NULL) 
          return; 
  
     /* first recur on left child */
     printInorder(node->left); 
  
     /* then print the data of node */
     printf("%c", node->data);   
  
     /* now recur on right child */
     printInorder(node->right); 
} 
  
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(node* node) 
{ 
     if (node == NULL) 
          return; 
  
     /* first prchar data of node */
     printf("%c", node->data);   
  
     /* then recur on left sutree */
     printPreorder(node->left);   
  
     /* now recur on right subtree */
     printPreorder(node->right); 
}     
  
/* Driver program to test above functions*/
int main() 
{ 
     node * root[27];
     int N;
     char a,b,c, arr[81][2];
     scanf("%d",&N);
     for (int i = 0; i < N; i++) {
        scanf(" %c %c %c", &a, &b, &c);
        arr[i][0] = b;
        arr[i][1] = c;
        root[i] = createnode(a);
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][0] == root[j]->data)
                root[i]->left = root[j];
            //arr배열의 1번째 열에 저장된 값은 노드의 오른쪽 자식 노드가 된다.
            //배열에 저장된 값과 노드의 데이터(root->data)가 같을 때 그 노드를 오른쪽 자식노드로 저장 
            if (arr[i][1] == root[j]->data)
                root[i]->right = root[j];
        }
    }
     printPreorder(root[0]);  
     printf("\n");
     printInorder(root[0]);
     printf("\n");
     printPostorder(root[0]);
     return 0; 
} 