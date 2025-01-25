// //
// // Created by Diego Torres Durante on 10/9/24.
// // Modified by ChatGPT on 04/27/24.
// // https://youtu.be/Vtckgz38QHs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// // Function Prototypes
// int partition(int arr[], int start, int end);
// void quickSort(int arr[], int start, int end);
// void selectionSort(int arr[], int size);
// void insertionSort(int arr[], int size);
// void bubbleSort(int arr[], int size);
// void shellSort(int arr[], int size);
// void mergeSortAlg(int arr[], int left, int right);
// void merge(int arr[], int left, int mid, int right);
// int genRandomArray(int *nums, int quantity);
// void sortingPerformance(void (*sortFunc)(int *, int, int), const char *sortName);
// void copyArray(int *source, int *destination, int size);
//
// // Quick Sort Implementation
// int partition(int arr[], int start, int end) {
//     int pivot = arr[end];
//     int i = start - 1;
//
//     for (int j = start; j <= end - 1; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             // Swap arr[i] and arr[j]
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }
//     i++;
//     // Swap arr[i] and arr[end] (pivot)
//     int temp = arr[i];
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
// // Selection Sort Implementation
//     void selectionSort(int arr[], int size) {
//         for (int i = 0; i < size -1; i++) {
//             int min_idx = i;
//             for (int j = i+1; j < size; j++) {
//                 if (arr[j] < arr[min_idx])
//                     min_idx = j;
//             }
//             // Swap arr[i] and arr[min_idx]
//             int temp = arr[i];
//             arr[i] = arr[min_idx];
//             arr[min_idx] = temp;
//         }
//     }
//
// // Insertion Sort Implementation
// void insertionSort(int arr[], int size) {
//     for (int i = 1; i < size; i++) {
//         int key = arr[i];
//         int j = i -1;
//         while (j >=0 && arr[j] > key) {
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = key;
//     }
// }
//
// // Bubble Sort Implementation
// void bubbleSort(int arr[], int size) {
//     int swapped;
//     for (int i =0; i < size-1; i++) {
//         swapped = 0;
//         for (int j =0; j < size-i-1; j++) {
//             if (arr[j] > arr[j+1]) {
//                 // Swap arr[j] and arr[j+1]
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//                 swapped =1;
//             }
//         }
//         // If no two elements were swapped by inner loop, then break
//         if (!swapped)
//             break;
//     }
// }
//
// // Shell Sort Implementation
// void shellSort(int arr[], int size) {
//     // Start with a big gap, then reduce the gap
//     for (int gap = size/2; gap >0; gap /=2) {
//         // Do a gapped insertion sort for this gap size.
//         for (int i = gap; i < size; i++) {
//             int temp = arr[i];
//             int j;
//             for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
//                 arr[j] = arr[j - gap];
//             arr[j] = temp;
//         }
//     }
// }

// Merge Sort Implementation
void merge(char arr[], int left, int mid, int right) {
    int n1 = mid - left +1;
    int n2 = right - mid;

    // Create temp arrays
    char *L = (char *)malloc(n1 * sizeof(char));
    char *R = (char *)malloc(n2 * sizeof(char));

    // Copy data to temp arrays L[] and R[]
    for (int i =0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j =0; j < n2; j++)
        R[j] = arr[mid +1 + j];

    // Merge the temp arrays back into arr[l..r]
    int i =0, j=0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
        arr[k++] = L[i++];

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
        arr[k++] = R[j++];

    // Free temporary arrays
    free(L);
    free(R);
}

void mergeSortAlg(char arr[], int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left)/2;
    mergeSortAlg(arr, left, mid);
    mergeSortAlg(arr, mid+1, right);
    merge(arr, left, mid, right);
}
//
// // Function to Generate Random Array
// int genRandomArray(int *nums, int quantity) {
//     srand(time(0));  // Initialize random seed
//     for (int i = 0; i < quantity; i++) {
//         int num = (rand() % 1000000) + 1; // Generate numbers between 1 and 1,000,000
//         nums[i] = num;
//     }
//     return 0;
// }
//
// // Function to Copy Array
// void copyArray(int *source, int *destination, int size) {
//     memcpy(destination, source, size * sizeof(int));
// }
//
// // Function to Measure Sorting Performance
// void sortingPerformance(void (*sortFunc)(int *, int, int), const char *sortName) {
//     int size = 10000;
//     int original[size];
//     int nums[size];
//     clock_t start_time, end_time;
//     double time_taken;
//
//     // Generate 10k random array
//     genRandomArray(original, size);
//
//     printf("=== Testing %s ===\n\n", sortName);
//
//     // Test 1: 10k Random Array
//     copyArray(original, nums, size);
//     printf("Test 1: 10k Random Array\n");
//     start_time = clock();
//     // For sort functions that require start and end indices
//     if (strcmp(sortName, "Merge Sort") == 0 || strcmp(sortName, "Quick Sort") == 0)
//         sortFunc(nums, 0, size -1);
//     else
//         sortFunc(nums, size, 0); // For sorts that don't use start/end, size is used
//     end_time = clock();
//     time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
//     printf("Time Taken: %.6f seconds\n", time_taken);
//
//     // Verify if sorted (optional)
//     /*
//     for (int i =0; i < size; i++) {
//         printf("%d ", nums[i]);
//     }
//     printf("\n");
//     */
//     printf("\n");
//
//     // Test 2: 10k Already Sorted Array
//     copyArray(original, nums, size);
//     // Sort once to make it sorted
//     if (strcmp(sortName, "Merge Sort") == 0 || strcmp(sortName, "Quick Sort") == 0)
//         sortFunc(nums, 0, size -1);
//     else
//         sortFunc(nums, size, 0);
//     printf("Test 2: 10k Already Sorted Array\n");
//     start_time = clock();
//     if (strcmp(sortName, "Merge Sort") == 0 || strcmp(sortName, "Quick Sort") == 0)
//         sortFunc(nums, 0, size -1);
//     else
//         sortFunc(nums, size, 0);
//     end_time = clock();
//     time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
//     printf("Time Taken: %.6f seconds\n", time_taken);
//     printf("\n");
//
//     // Test 3: 10k Sorted Array Minus the Last One
//     copyArray(original, nums, size);
//     if (strcmp(sortName, "Merge Sort") == 0 || strcmp(sortName, "Quick Sort") == 0)
//         sortFunc(nums, 0, size -1);
//     else
//         sortFunc(nums, size, 0);
//     nums[size -1] = 0; // Modify last element to make it nearly sorted
//     printf("Test 3: 10k Sorted Array Minus the Last One\n");
//     start_time = clock();
//     if (strcmp(sortName, "Merge Sort") == 0 || strcmp(sortName, "Quick Sort") == 0)
//         sortFunc(nums, 0, size -1);
//     else
//         sortFunc(nums, size, 0);
//     end_time = clock();
//     time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
//     printf("Time Taken: %.6f seconds\n", time_taken);
//     printf("\n");
//
//     // Test 4: 10k Sorted Array Minus the First One
//     copyArray(original, nums, size);
//     if (strcmp(sortName, "Merge Sort") == 0 || strcmp(sortName, "Quick Sort") == 0)
//         sortFunc(nums, 0, size -1);
//     else
//         sortFunc(nums, size, 0);
//     nums[0] = 1000001; // Modify first element to make it nearly sorted
//     printf("Test 4: 10k Sorted Array Minus the First One\n");
//     start_time = clock();
//     if (strcmp(sortName, "Merge Sort") == 0 || strcmp(sortName, "Quick Sort") == 0)
//         sortFunc(nums, 0, size -1);
//     else
//         sortFunc(nums, size, 0);
//     end_time = clock();
//     time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
//     printf("Time Taken: %.6f seconds\n", time_taken);
//     printf("\n");
//
//     printf("====================================\n\n");
// }
//
// int main() {
//     // Array size
//     int size = 10000;
//     // Allocate memory for the array
//     int *nums = (int *)malloc(size * sizeof(int));
//     if (nums == NULL) {
//         printf("Memory allocation failed!\n");
//         return 1;
//     }
//
//     // Define sorting algorithms and their corresponding function pointers
//     typedef struct {
//         const char *name;
//         void (*func)(int *, int, int);
//     } SortAlgorithm;
//
//     SortAlgorithm algorithms[] = {
//         {"Selection Sort", (void (*)(int *, int, int))selectionSort},
//         {"Insertion Sort", (void (*)(int *, int, int))insertionSort},
//         {"Bubble Sort",    (void (*)(int *, int, int))bubbleSort},
//         {"Shell Sort",     (void (*)(int *, int, int))shellSort},
//         {"Merge Sort",     (void (*)(int *, int, int))mergeSortAlg},
//         {"Quick Sort",     (void (*)(int *, int, int))quickSort}
//     };
//
//     int numAlgorithms = sizeof(algorithms)/sizeof(algorithms[0]);
//
//     // Iterate through each sorting algorithm and perform tests
//     for (int i =0; i < numAlgorithms; i++) {
//         sortingPerformance(algorithms[i].func, algorithms[i].name);
//     }
//
//     // Free allocated memory
//     free(nums);
//
//     return 0;
// }