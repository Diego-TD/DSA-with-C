//
// //
// // Created by Diego Torres Durante on 9/25/24.
// // Linked list for Integers
// //
//
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// struct Node {
//     int data;
//     struct Node *next;
// };
//
// struct LinkedList {
//     struct Node *head;
//     struct Node *tail;
//     int size;
// };
//
// void initializeLinkedList(struct LinkedList *List) {
//     List->head = NULL;
//     List->tail = NULL;
//     List->size = 0;
// }
//
// struct Node* createNode(const int data) {
//     struct Node* newNode = malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }
//
// void addFirst(struct LinkedList *list, const int data) {
//     struct Node* node = createNode(data);
//     if (list->head == NULL) {
//         list->head = node;
//         list->tail = node;
//     } else {
//         node->next = list->head;
//         list->head = node;
//     }
//     list->size++;
// }
//
// void insertAt(struct LinkedList *list, int data, int position) {
//
// }
//
// struct Node* findPrevOrderNode(struct LinkedList *list, int data) {
//     //assuming the list is ordered
//     struct Node* prev;
//     struct Node* current;
//
//     //corner cases
//     // corner case unordered list
//     // duplicated values doesnt matter here
//     // sort
//     //
//
//     current = list->head;
//     while (data >= prev->data && current->next != NULL ) {
//         if (current->data >= data) {
//
//         }
//     }
//
//
//
// }
//
//
// void insertOrdered(struct LinkedList *list, int data) {
//     struct Node* newNode = createNode(data);
//     struct Node* prev = findPrevOrderNode(list, data);
//
//     newNode->next = prev->next;
//     prev->next = newNode;
// }
//
//
// void addLast(struct LinkedList *list, const int data) {
//     struct Node* node = createNode(data);
//     if (list->head == NULL) {
//         list->head = node;
//         list->tail = node;
//     } else {
//         list->tail->next = node;
//         list->tail = node;
//     }
//     list->size++;
// }
//
// void removeFirst(struct LinkedList *list) {
//     if (list->head == NULL) {
//         return;
//     }
//     if (list->head == list->tail) {
//         free(list->head);
//         list->head = NULL;
//         list->tail = NULL;
//         list->size--;
//     } else {
//         struct Node* temp = list->head;
//         list->head = temp->next;
//         free(temp);
//         list->size--;
//     }
// }
// void removeLast(struct LinkedList *list) {
//     if (list->head == NULL) {
//         return;
//     }
//     if (list->head == list->tail) {
//         free(list->head);
//         list->head = NULL;
//         list->tail = NULL;
//         list->size--;
//         return;
//     }
//
//     struct Node* current = list->head;
//     while (current->next != list->tail) {
//         current = current->next;
//     }
//
//     free(list->tail);
//     list->tail = current;
//     list->tail->next = NULL;
//     list->size--;
// }
//
// int peek(struct LinkedList *list) {
//     return list->tail->data;
// }
//
// bool contains(struct LinkedList *list, int data) {
//     struct Node *current = list->head;
//     while (current != NULL) {
//         if (current->data == data) {
//             return true;
//         }
//         current = current->next;
//     }
//     return false;
// }
//
// bool isEmpty(struct LinkedList *list) {
//     if (list->head == NULL) {
//         return true;
//     }
//     return false;
// }
//
// int size(struct LinkedList *list) {
//     return list->size;
// }
//
// void printLinkedList(struct LinkedList *list) {
//     struct Node *current = list->head;
//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }
//
// // search(value)
// struct Node* search(struct LinkedList *list, int data) {
//     struct Node* current = &list->head;
//     if (list->size == 0) {
//         return NULL;
//     }
//
//     while(current->data == data && current->next != NULL) {
//         current = current->next;
//     }
//     return current;
//
// }
//
// // deleteAt(position)
//
//
//
//
//
// // int main () {
// //     struct LinkedList list;
// //     initializeLinkedList(&list);
// //
// //     // Test adding first element
// //     addFirst(&list, 1);
// //     printf("After addFirst(1): ");
// //     printLinkedList(&list);
// //     printf("Size: %d, Head: %d, Tail: %d\n", size(&list), list.head->data, list.tail->data);
// //
// //     // Test adding last element
// //     addLast(&list, 2);
// //     printf("After addLast(2): ");
// //     printLinkedList(&list);
// //     printf("Size: %d, Head: %d, Tail: %d\n", size(&list), list.head->data, list.tail->data);
// //
// //     // Test remove first
// //     removeFirst(&list);
// //     printf("After removeFirst: ");
// //     printLinkedList(&list);
// //     printf("Size: %d, Head: %d, Tail: %d\n", size(&list), list.head->data, list.tail->data);
// //
// //     // Test remove last
// //     removeLast(&list);
// //     printf("After removeLast: ");
// //     printLinkedList(&list);
// //     printf("Size: %d\n", size(&list));
// //
// //     // Test adding multiple elements
// //     addLast(&list, 3);
// //     addLast(&list, 4);
// //     addFirst(&list, 0);
// //     printf("After adding multiple elements: ");
// //     printLinkedList(&list);
// //     printf("Size: %d\n", size(&list));
// //
// //     // Test removeLast on non-empty list
// //     removeLast(&list);
// //     printf("After removeLast: ");
// //     printLinkedList(&list);
// //     printf("Size: %d\n", size(&list));
// //
// //     // Test contains
// //     printf("Contains 3: %s\n", contains(&list, 3) ? "true" : "false");
// //     printf("Contains 5: %s\n", contains(&list, 5) ? "true" : "false");
// //
// //     // Test peek
// //     printf("Peek: %d\n", peek(&list));
// //
// //    return 0;
// // }
// //
//
