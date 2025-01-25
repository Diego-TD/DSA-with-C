// //
// // Created by Diego Torres Durante on 9/23/24.
// //
//
// #include <stdio.h>
// #include <stdlib.h>
//
// struct Node {
//     int data;
//     struct Node *next;
// };
//
// struct LinkedQueue {
//     struct Node *front, *rear;
//     int size;
// };
//
// void addNode(struct LinkedQueue *queue, const int data) {
//     struct Node *newNode = malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//
//     if (queue->front ==  NULL) {
//         queue->front = newNode;
//         queue->rear = newNode;
//     } else {
//         queue->rear->next = newNode;
//     }
// }
//
// void initializeQueue(struct LinkedQueue *q) {
//     q->front = q->rear = NULL;
//     q->size = 0;
// }
//
// // int main() {
// //     struct LinkedQueue queue;
// //     initializeQueue(&queue);
// //
// //
// //
// //     return 0;
// // }
//
