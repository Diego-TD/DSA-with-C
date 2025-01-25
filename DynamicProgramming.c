// //
// // Created by Diego Torres Durante on 11/13/24.
// //
//
// #include <stdio.h>
// // Given an array with positive and integer numbers.
//
// void bruteForceApproachN3(int a[], int size) {
//     int maxSum = 0;
//     int tempSum = 0;
//     for (int i = 0; i < size; ++i) { //n
//         for (int j = i; j < size; ++j) { //
//             tempSum = 0;
//             for (int k = i; k <= j; ++k) {
//
//                 tempSum += a[k];
//                 if (tempSum > maxSum) {
//                     maxSum = tempSum;
//                 }
//             }
//         }
//     }
//     printf("Brute force max sum: %d\n", maxSum);
// }
//
// void bruteForceApproachN2(int a[], int size) {
//     int maxSum = 0;
//     int tempSum = 0;
//     for (int i = 0; i < size; ++i) { //n
//         tempSum = 0;
//         for (int j = i; j < size; ++j) { //
//                 tempSum += a[j];
//                 if (tempSum > maxSum) {
//                     maxSum = tempSum;
//                 }
//         }
//     }
//     printf("Brute force max sum: %d\n", maxSum);
// }
// int numeroMayor(int a, int b) {
//     if(a >= b) {
//         return a;
//     }
//     return b;
// }
//
// void bruteForceApproachN(int a[], int size) {
//     int maxSum = 0;
//     int tempSum = 0;
//     for (int i = 0; i < size; ++i) { //n
//         tempSum = numeroMayor(tempSum + a[i], a[i]);
//         maxSum = numeroMayor(maxSum, tempSum);
//     }
//     printf("Brute force max sum: %d\n", maxSum);
// }
//
// void getMaxConsecutiveSum(int a[], int size) {
//     // brute force
//     bruteForceApproachN3(a,size);
//     bruteForceApproachN2(a,size);
//     bruteForceApproachN(a,size);
//
// }
// int main () {
//     int a[6] = {-2,11,-4,13,-5,2};
//     int size = 6;
//
//     getMaxConsecutiveSum(a, size);
//
//
//     return 0;
// }