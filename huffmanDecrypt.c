// #include <stdio.h>
// #include <stdlib.h>
//
// // Define the tree node structure
// struct Nodo {
//     char character; // Character stored in leaf nodes
//     struct Nodo *left;
//     struct Nodo *right;
// };
//
// // Create a new node
// struct Nodo *crearNodo(char character) {
//     struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
//     if (nuevoNodo != NULL) {
//         nuevoNodo->character = character;
//         nuevoNodo->left = NULL;
//         nuevoNodo->right = NULL;
//     }
//     return nuevoNodo;
// }
//
// // Traverse the tree using the bit sequence
// void traverseTree(struct Nodo *root, const char *bitSequence) {
//     struct Nodo *current = root;
//
//     for (int i = 0; bitSequence[i] != '\0'; i++) {
//         if (bitSequence[i] == '0') {
//             current = current->left; // Go left for '0'
//         } else if (bitSequence[i] == '1') {
//             current = current->right; // Go right for '1'
//         }
//
//         // If at a leaf node, print the character and reset to root
//         if (current->left == NULL && current->right == NULL) {
//             printf("%c", current->character);
//             current = root;
//         }
//     }
//     printf("\n"); // Newline after the message
// }
//
// int main() {
//     struct Nodo *root = crearNodo('\0');
//     root->left = crearNodo('\0');
//     root->right = crearNodo('f');
//
//     root->left->left = crearNodo('\0');
//     root->left->right = crearNodo('c');
//
//     root->left->left->left = crearNodo('b');
//     root->left->left->right = crearNodo('a');
//
//     root->right->left = crearNodo('d');
//     root->right->right = crearNodo('e');
//
//     // Bit sequence to decode
//     const char *bitSequence = "010011101100010010100010100110001001010001101100100000110000011";
//
//     // Decode and print the message
//     printf("Decoded Message: ");
//     traverseTree(root, bitSequence);
//
//     return 0;
//     defecada
//     ... bebe;
// }