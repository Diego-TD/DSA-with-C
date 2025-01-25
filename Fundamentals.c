// //
// // Created by Diego Torres Durante on 10/22/24.
// //
//
// #include <stdio.h>
// #include <stdbool.h>
//
// /* Function declarations */
// void greet();
// int add(int x, int y);
// void manipulateArray(int arr[], int size);
// void pointerDemo();
//
// int main(){
//     /* Data types and variables */
//     int integer = 4;
//     char character = 'A';
//     float decimal = 4.4f;
//     double bigDecimal = 4.4444444;
//
//     struct Object {
//         int attribute;
//     };
//
//     /* Arithmetic operators */
//     short int smallInteger = 4;
//     long int bigInteger = 4444444444L;
//     // Note: Signed int cannot hold decimal values, changed to int
//     int negativeInteger = -4;
//     unsigned int positiveInteger = 444;
//
//     int addition = integer + smallInteger;
//     long int subtraction = bigInteger - (long int)bigDecimal;
//     float multiplication = decimal * bigDecimal;
//     int division = integer / smallInteger;
//     int modulo = integer % smallInteger;
//
//     /* Relational operators */
//     int a = 5, b = 10, c = 15, d = 20;
//     bool higher = a > b;
//     bool less = b < a;
//     bool equal = c == d;
//     bool notRel = !(a < b);
//     bool higherOrEqual = a >= b;
//     bool lessOrEqual = a <= b;
//
//     /* Logic operators */
//     bool andOperator = (a > b) && (b < c);
//     bool orOperator = (c == d) || (a != b);
//     bool negation = !(a < b);
//
//     /* Increment and decrement operators */
//     // As prefix
//     ++a;
//     // As postfix
//     a++;
//
//     // As prefix
//     --b;
//     // As postfix
//     b--;
//
//     /* Assignment operators */
//     int z = 10;
//     z += 10; // z = z + 10
//     z -= 10; // z = z - 10
//     z *= 10; // z = z * 10
//     z /= 10; // z = z / 10
//
//     /* Bitwise operators */
//
//     // a = 5 (00000101 in 8-bit binary), b = 9 (00001001 in 8-bit binary)
//     unsigned int bit_a = 5, bit_b = 9;
//
//     // The result is 00000001
//     printf("bit_a = %u, bit_b = %u\n", bit_a, bit_b);
//     printf("bit_a & bit_b = %u\n", bit_a & bit_b);
//
//     // The result is 00001101
//     printf("bit_a | bit_b = %u\n", bit_a | bit_b);
//
//     // The result is 00001100
//     printf("bit_a ^ bit_b = %u\n", bit_a ^ bit_b);
//
//     // The result is 11111111111111111111111111111010 (assuming 32-bit unsigned int)
//     printf("~bit_a = %u\n", ~bit_a);
//
//     // The result is 00010010
//     printf("bit_b << 1 = %u\n", bit_b << 1);
//
//     // The result is 00000100
//     printf("bit_b >> 1 = %u\n", bit_b >> 1);
//
//     /* Control Structures */
//
//     // If-Else Statement
//     if (a > b) {
//         printf("a is greater than b\n");
//     } else {
//         printf("a is not greater than b\n");
//     }
//
//     // Switch Statement
//     char grade = 'B';
//     switch (grade) {
//         case 'A':
//             printf("Excellent!\n");
//             break;
//         case 'B':
//         case 'C':
//             printf("Well done\n");
//             break;
//         case 'D':
//             printf("You passed\n");
//             break;
//         case 'F':
//             printf("Better try again\n");
//             break;
//         default:
//             printf("Invalid grade\n");
//     }
//
//     /* Loops */
//
//     // For Loop
//     printf("For Loop: Counting from 1 to 5\n");
//     for(int i = 1; i <= 5; i++) {
//         printf("%d ", i);
//     }
//     printf("\n");
//
//     // While Loop
//     printf("While Loop: Counting from 1 to 5\n");
//     int j = 1;
//     while(j <= 5) {
//         printf("%d ", j);
//         j++;
//     }
//     printf("\n");
//
//     // Do-While Loop
//     printf("Do-While Loop: Counting from 1 to 5\n");
//     int k = 1;
//     do {
//         printf("%d ", k);
//         k++;
//     } while(k <= 5);
//     printf("\n");
//
//     /* Functions */
//     greet();
//     int sum = add(10, 20);
//     printf("Sum of 10 and 20 is %d\n", sum);
//
//     /* Arrays */
//     int numbers[5] = {1, 2, 3, 4, 5};
//     printf("Array elements: ");
//     for(int i = 0; i < 5; i++) {
//         printf("%d ", numbers[i]);
//     }
//     printf("\n");
//     manipulateArray(numbers, 5);
//
//     /* Pointers */
//     pointerDemo();
//
//     /* Input/Output */
//     int userInput;
//     printf("Enter an integer: ");
//     if(scanf("%d", &userInput) == 1){
//         printf("You entered: %d\n", userInput);
//     } else {
//         printf("Invalid input.\n");
//     }
//
//     /* Structures */
//     struct Object obj;
//     obj.attribute = 100;
//     printf("Object attribute: %d\n", obj.attribute);
//
//     printf("Hello world\n");
//     return 0;
// }
//
// /* Function Definitions */
//
// /* Function to print a greeting message */
// void greet(){
//     printf("Welcome to the C program!\n");
// }
//
// /* Function to add two integers */
// int add(int x, int y){
//     return x + y;
// }
//
// /* Function to manipulate and print array elements */
// void manipulateArray(int arr[], int size){
//     printf("Manipulating array elements:\n");
//     for(int i = 0; i < size; i++) {
//         arr[i] *= 2;
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
//
// /* Function to demonstrate pointers */
// void pointerDemo(){
//     int var = 10;
//     int *ptr = &var;
//
//     printf("Pointer Demo:\n");
//     printf("Value of var: %d\n", var);
//     printf("Address of var: %p\n", (void*)&var);
//     printf("Pointer ptr points to address: %p\n", (void*)ptr);
//     printf("Value pointed to by ptr: %d\n", *ptr);
// }
