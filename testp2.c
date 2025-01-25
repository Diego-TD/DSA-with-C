// //
// // Created by Diego Torres Durante on 10/21/24.
// //
//
// #include <stdio.h>
//
// void insertionSortDescendiente(int arr[], int n) {
//     for (int i = 1; i < n; i++) {
//         int key = arr[i];
//         int j = i - 1;
//
//         while (j >= 0 && arr[j] < key) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//
//         arr[j + 1] = key;
//     }
// }
//
// // Función para implementar Insertion Sort
// void insertionSort(int arr[], int n) {
//     for (int i = 1; i < n; i++) {
//         int key = arr[i];
//         int j = i - 1;
//
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//
//         arr[j + 1] = key;
//     }
// }
//
// // Función para imprimir el arreglo
//
// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
//
// void userSortArray() {
//     // Solicitar al usuario la cantidad de elementos
//     int n;
//     printf("Ingrese la cantidad de elementos: ");
//     scanf("%d", &n);
//
//     int arr[n];
//
//     // Solicitar al usuario que ingrese los elementos del arreglo
//     printf("Ingrese los elementos (enteros):\n");
//     for (int i = 0; i < n; i++) {
//         printf("Elemento %d: ", i);
//         scanf("%d", &arr[i]);
//     }
//
//     // Mostrar el arreglo antes de ordenar
//     printf("Arreglo antes de ordenar:\n");
//     printArray(arr, n);
//
//
//     int option = 0;
//     printf("Selecciona el tipo de ordenamiento:\n"
//            "1) ASCENDENTE\n"
//            "2) DESCENDENTE\n");
//     scanf("%d", &option);
//
//     if (option ==1) {
//         // Llamar a la función de Insertion Sort
//         insertionSort(arr, n);
//
//     } else if (option == 2) {
//         // Llamar a la función de Insertion Sort Descenduiente
//         insertionSortDescendiente(arr, n);
//
//     } else {
//         printf("error");
//         return;
//     }
//
//     // Mostrar el arreglo después de ordenar
//     printf("Arreglo después de ordenar:\n");
//     printArray(arr, n);
// }
//
// // int main() {
// //     userSortArray();
// // }
//
//
// /* Ejemplo descendiente
// Ingrese la cantidad de elementos: 20
// Ingrese los elementos (enteros):
// Elemento 0: 7
// Elemento 1: 3
// Elemento 2: 754
// Elemento 3: 24
// Elemento 4: 4574
// Elemento 5: 572
// Elemento 6: 4562
// Elemento 7: 457
// Elemento 8: 568
// Elemento 9: 35
// Elemento 10: 23
// Elemento 11: 452
// Elemento 12: 34654
// Elemento 13: 35
// Elemento 14: 623
// Elemento 15: 45
// Elemento 16: 23457
// Elemento 17: 4
// Elemento 18: 56
// Elemento 19: 2345
// Arreglo antes de ordenar:
// 7 3 754 24 4574 572 4562 457 568 35 23 452 34654 35 623 45 23457 4 56 2345
// Selecciona el tipo de ordenamiento:
// 1) ASCENDENTE
// 2) DESCENDENTE
// 1
// Arreglo después de ordenar:
// 3 4 7 23 24 35 35 45 56 452 457 568 572 623 754 2345 4562 4574 23457 34654
//
// Process finished with exit code 0
//  */
//
// /*
//  *Ejemplo ascendiente
// Ingrese la cantidad de elementos: 20
// Ingrese los elementos (enteros):
// Elemento 0: 9
// Elemento 1:
// 2345
// Elemento 2:
// 964
// Elemento 3: 78
// Elemento 4: 2
// Elemento 5: 346
// Elemento 6: 7
// Elemento 7: 89
// Elemento 8: 623
// Elemento 9: 45
// Elemento 10: 793
// Elemento 11: 456
// Elemento 12: 793
// Elemento 13:
// 524
// Elemento 14: 5768
// Elemento 15: 462345
// Elemento 16: 83
// Elemento 17: 623
// Elemento 18: 2452
// Elemento 19: 457
// Arreglo antes de ordenar:
// 9 2345 964 78 2 346 7 89 623 45 793 456 793 524 5768 462345 83 623 2452 457
// Selecciona el tipo de ordenamiento:
// 1) ASCENDENTE
// 2) DESCENDENTE
// 1
// Arreglo después de ordenar:
// 2 7 9 45 78 83 89 346 456 457 524 623 623 793 793 964 2345 2452 5768 462345
//
// Process finished with exit code 0
//  */