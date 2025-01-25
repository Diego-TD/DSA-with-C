// //
// // Created by Diego Torres Durante on 10/9/24.
// // https://youtu.be/Vtckgz38QHs
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
//
// int partition(int arr[], int start, int end) {
//     int pivot = arr[end];
//     int i = start - 1;
//
//     for (int j = start; j <= end - 1; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }
//     i++;
//     int temp = arr[i];  // Final swap with pivot
//     arr[i] = arr[end];
//     arr[end] = temp;
//
//     return i;
// }
//
// void quickSort(int arr[], int start, int end) {
//     if (end <= start) return;
//
//     int pivot = partition(arr, start, end);
//     quickSort(arr, start, pivot - 1);
//     quickSort(arr, pivot + 1, end);
// }
//
//
//
//
//
// int genRandomArray(int *nums, int quantity) {
//     srand (time(0));
//     for (int i = 0; i < quantity; i++) {
//         int num = (rand() % 1000000) + 1; // Genera números entre 1 y 1 millón
//         nums [i] = num;
//     }
//     return 0;
// }
//
// // int main() {
// //     int size = 10000;
// //     int nums[size];
// //
// //     /* 10k random */
// //     genRandomArray(nums, size);
// //     printf("Original array (first 10000 elements):\n");
// //     for (int i = 0; i < size; i++) {  //10  Limiting output for readability
// //         printf("%d ", nums[i]);
// //     }
// //     printf("...\n\n");
// //
// //     // Time the quickSort for 10k random
// //     clock_t start_time, end_time;
// //     double time_taken;
// //
// //     start_time = clock();
// //     quickSort(nums, 0, size - 1);
// //     end_time = clock();
// //     time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
// //     printf("QuickSort on 10k random array took %.6f seconds.\n", time_taken);
// //
// //     printf("Sorted array (Quick sort 10k random): \n");
// //     for (int i = 0; i < size; i++) {  // Limiting output for readability
// //         printf("%d ", nums[i]);
// //     }
// //     printf("...\n\n");
// //
// //     /* 10k sorted */
// //     // Time the quickSort for already sorted array
// //     start_time = clock();
// //     quickSort(nums, 0, size - 1);
// //     end_time = clock();
// //     time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
// //     printf("QuickSort on 10k already sorted array took %.6f seconds.\n", time_taken);
// //
// //     printf("Sorted array (Quick sort 10k sorted): \n");
// //     for (int i = 0; i < size; i++) {  // Limiting output for readability
// //         printf("%d ", nums[i]);
// //     }
// //     printf("...\n\n");
// //
// //     /* 10k sorted minus the last one */
// //     nums[size - 1] = 0;    // Modify last element
// //
// //     // Time the quickSort for nearly sorted array (last element modified)
// //     start_time = clock();
// //     quickSort(nums, 0, size - 1);
// //     end_time = clock();
// //     time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
// //     printf("QuickSort on 10k sorted array with last element modified took %.6f seconds.\n", time_taken);
// //
// //     printf("Sorted array (Quick sort 10k sorted minus the last one): \n");
// //     for (int i = 0; i < 10; i++) {  // Limiting output for readability
// //         printf("%d ", nums[i]);
// //     }
// //     printf("...\n\n");
// //
// //     /* 10k sorted minus the first one */
// //     nums[0] = 1000001;    // Modify first element
// //
// //     // Time the quickSort for nearly sorted array (first element modified)
// //     start_time = clock();
// //     quickSort(nums, 0, size - 1);
// //     end_time = clock();
// //     time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
// //     printf("QuickSort on 10k sorted array with first element modified took %.6f seconds.\n", time_taken);
// //
// //     printf("Sorted array (Quick sort 10k sorted minus the first one): \n");
// //     for (int i = 0; i < size; i++) {  // Limiting output for readability
// //         printf("%d ", nums[i]);
// //     }
// //     printf("...\n\n");
// //
// //     return 0;
// // }