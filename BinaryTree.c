// //
// // Created by Diego Torres Durante on 10/16/24.
// //
//
//
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
//
// struct TreeNode {
//     int value;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };
//
// // struct BinaryTree {
// //     struct TreeNode *root;
// // };
//
//
//
// struct TreeNode* createNode(const int value) {
//     struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
//     newNode->value = value;
//     newNode->left = NULL;
//     newNode->right = NULL;
//
//     return newNode;
// }
//
// /* Insert node to a binary search tree without duplicates */
// struct TreeNode* insertNode(struct TreeNode* root, const int value) {
//
//     if (root==NULL) {
//         return createNode(value);
//     }
//
//     if (value < root->value) {
//         root->left = insertNode(root->left,value);
//     } else if (value > root->value) {
//         root->right = insertNode(root->right,value);
//     }
//
//     return root;
// }
//
//
// //preorder
// void preorder(struct TreeNode* root) {
//     if (root == NULL) {
//         return;
//     }
//     printf("%d \n",root->value);
//
//     preorder(root->left);
//     preorder(root->right);
// }
//
// //inorder LDR
// void inorder(struct TreeNode* root) {
//     if (root == NULL) {
//         return;
//     }
//
//     inorder(root->left);
//     printf("%d \n",root->value);
//     inorder(root->right);
// }
//
//
// //postorder LRD
// void postorder(struct TreeNode* root) {
//     if (root == NULL) {
//         return;
//     }
//
//     postorder(root->left);
//     postorder(root->right);
//     printf("%d \n",root->value);
//
// }
//
// //espejo al arbol (tarea)
// void flipArbol(struct TreeNode *root) {
//     if (root == NULL) {
//         return;
//     }
//     struct TreeNode *temp;
//
//     temp = root->left;
//     root->left = root->right;
//     root->right = temp;
//
//     flipArbol(root->left);
//     flipArbol(root->right);
// }
//
//
// // deleteNode (tarea, in progress)
// void deleteNode(struct TreeNode *root, int value) {
//     if (root==NULL) {
//         return;
//     }
//
//     if (root->value == value) {
//         root = NULL;
//         return;
//     }
//
//     if (value < root->value) {
//         deleteNode(root->left,value);
//     } else if (value > root->value) {
//         deleteNode(root->right,value);
//     }
//
//
// }
//
//
//
// void printTree(struct TreeNode* root, int space) {
//     int COUNT = 5; // Defines the spacing between levels
//     if (root == NULL)
//         return;
//
//     // Increase distance between levels
//     space += COUNT;
//
//     // Process right subtree first
//     printTree(root->right, space);
//
//     // Print current node after spacing
//     printf("\n");
//     for (int i = COUNT; i < space; i++)
//         printf(" ");
//     printf("%d\n", root->value);
//
//     // Process left subtree
//     printTree(root->left, space);
// }
//
//
// int main() {
//     struct TreeNode *root = NULL;
//
//     int values[] = {10, 5, 15, 5, 20, 2, 1, 3}; // 2, 1, 3, 45, 15, 13, 16, 7, 4, 8, 9
//     int n = sizeof(values) / sizeof(values[0]);
//
//     for(int i = 0; i < n; i++) {
//         root = insertNode(root, values[i]);
//     }
//
//     printf("Values to insert: \n");
//     for (int i = 0; i < n; ++i) {
//         printf("%d, ",values[i]);
//     }
//     printf("\n\nTree:\n\n");
//     printTree(root,10);
//
//     // printf("\n\npreorder: \n");
//     // preorder(root);
//     //
//     // printf("inorder: \n");
//     // inorder(root);
//     //
//     // printf("postorder: \n");
//     // postorder(root);
//
//     flipArbol(root);
//     printf("\nTree flipped:\n");
//     printTree(root, 10);
//     //
//     // for(int i = 0; i < n; i++) {
//     //     deleteNode(root, values[i]);
//     // }
//     //
//     // printf("\n\nTree:\n\n");
//     // printTree(root,10);
//
//     return 0;
// }