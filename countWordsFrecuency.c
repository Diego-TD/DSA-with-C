// //
// // Created by Diego Torres Durante on 12/2/24.
// //
//
// #include <stdio.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <string.h>
//
// #define MAX_TOKENS 100
// #define TABLE_SIZE 100
//
// typedef struct HashNode {
//     char *key;
//     int value;
//     struct HashNode *next;
// } HashNode;
//
// typedef struct HashMap {
//     HashNode *table[TABLE_SIZE];
// } HashMap;
//
// unsigned int hash(const char *key) {
//     unsigned int hash = 0;
//     while (*key) {
//         hash = (hash * 31) + *key++;
//     }
//     return hash % TABLE_SIZE;
// }
//
// HashMap *createHashMap() {
//     HashMap *map = (HashMap *)malloc(sizeof(HashMap));
//     if (!map) {
//         perror("Failed to allocate hashmap");
//         exit(EXIT_FAILURE);
//     }
//     memset(map->table, 0, sizeof(map->table));
//     return map;
// }
//
// HashNode *createNode(const char *key, int value) {
//     HashNode *node = (HashNode *)malloc(sizeof(HashNode));
//     if (!node) {
//         perror("Failed to allocate hash node");
//         exit(EXIT_FAILURE);
//     }
//     node->key = strdup(key);
//     node->value = value;
//     node->next = NULL;
//     return node;
// }
//
// void add(HashMap *map, const char *key) {
//     unsigned int index = hash(key);
//     HashNode *current = map->table[index];
//
//     while (current) {
//         if (strcmp(current->key, key) == 0) {
//             current->value++;
//             return;
//         }
//         current = current->next;
//     }
//
//     HashNode *newNode = createNode(key, 1);
//     newNode->next = map->table[index];
//     map->table[index] = newNode;
// }
//
// void printHashMap(HashMap *map) {
//     for (int i = 0; i < TABLE_SIZE; i++) {
//         HashNode *current = map->table[i];
//         while (current) {
//             printf("Key: %s, Count: %d\n", current->key, current->value);
//             current = current->next;
//         }
//     }
// }
//
// void freeHashMap(HashMap *map) {
//     for (int i = 0; i < TABLE_SIZE; i++) {
//         HashNode *current = map->table[i];
//         while (current) {
//             HashNode *temp = current;
//             current = current->next;
//             free(temp->key);
//             free(temp);
//         }
//     }
//     free(map);
// }
//
// // Función que simula split en C
// char** split(const char* str, const char* delimiter, int* count) {
//     // Crear un arreglo para almacenar los tokens
//     char** tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
//     char* tempStr = strdup(str);  // Hacemos una copia de la cadena para no modificar la original
//     char* token;
//
//     *count = 0;  // Contador de tokens
//
//     // Usamos strtok para dividir la cadena
//     token = strtok(tempStr, delimiter);
//     while (token != NULL) {
//         tokens[*count] = strdup(token);  // Almacenamos el token en el arreglo
//         (*count)++;
//         token = strtok(NULL, delimiter);
//     }
//
//     return tokens;  // Regresamos el arreglo de tokens
// }
//
// int main() {
//     HashMap *map = createHashMap();
//     const char* str = "hola hola dos dos habia una vez una vez";
//     const char* delimiter = " ";  // Delimitador por espacio
//     int count = 0;
//
//
//     // Llamamos a la función split
//     char** tokens = split(str, delimiter, &count);
//
//     // Mostramos los tokens
//     printf("Tokens:\n");
//     for (int i = 0; i < count; i++) {
//         add(map, tokens[i]);
//         // printf("%s\n", tokens[i]);
//         free(tokens[i]);  // Liberamos cada token
//     }
//
//     free(tokens);  // Liberamos el arreglo de punteros
//
//     printHashMap(map);
//
//     return 0;
// }
//
