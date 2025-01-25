// //
// // Created by Diego Torres Durante on 12/2/24.
// //
//
// #include <stdbool.h>
// #include <stdio.h>
//
// int roundFloat(const float num) {
//     bool isNegative = false;
//     if (0 + num < 0) {
//         isNegative = true;
//     }
//
//     int roundedNumber = (int)num;
//
//     if (!isNegative) {
//         const float mid = (int)num+.5;
//         if (num > mid) {
//             roundedNumber++;
//         }
//         return roundedNumber;
//     }
//
//     const float mid = (int)num-.5;
//     if (num < mid) {
//         roundedNumber--;
//     }
//     return roundedNumber;
// }
//
// void main() {
//     float test1 =  5.1;
//     printf("Float number %f, rounded float: %d\n",test1, roundFloat(test1));
//
//     test1 = 9.8;
//     printf("Float number %f, rounded float: %d\n",test1, roundFloat(test1));
//
//     test1 = 0;
//     printf("Float number %f, rounded float: %d\n",test1, roundFloat(test1));
//
//     test1 = -9.8;
//     printf("Float number %f, rounded float: %d\n",test1, roundFloat(test1));
//
//     test1 =  -5.1;
//     printf("Float number %f, rounded float: %d\n",test1, roundFloat(test1));
// }
