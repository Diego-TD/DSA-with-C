// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdbool.h>
//
// //
// // Created by Diego Torres Durante on 9/18/24.
// //
//
// #define MAX 100
//
// typedef struct {
//     char data[MAX];
//     int top;
// } Stack;
//
// void initStack(Stack *s) {
//     s->top = -1;
// }
//
// void push(Stack *s, char value) {
//     if (s->top == MAX - 1) {
//         printf("Stack Overflow\n");
//     } else {
//         s->data[++(s->top)] = value;
//     }
// }
//
// char pop(Stack *s) {
//     if (s->top == -1) {
//         printf("Stack Underflow\n");
//         return '\0';
//     } else {
//         return s->data[(s->top)--];
//     }
// }
//
// int isEmpty(Stack *s) {
//     return s->top == -1;
// }
//
// char peek(Stack *s) {
//     if (s->top == -1) {
//         printf("Stack is empty\n");
//         return '\0';
//     } else {
//         return s->data[s->top];
//     }
// }
//
// bool validParenthesis(char parenthesis, Stack &s) {
//     if (isEmpty(&parenthesis)) {
//         printf("Stack is empty\n");
//         return false;
//     }
//
//     switch (parenthesis) {
//         case ')': return peek(&s) == '(';
//         case '}': return peek(&s) == '{';
//         case ']': return peek(&s) == '[';
//         default: return false;
//     }
// }
//
// void solveSimpleMathExpresions(char *expresion) {
//     Stack nums;
//     Stack exps;
//     Stack parenthesis;
//
//     initStack(&nums);
//     initStack(&exps);
//     initStack(&parenthesis);
//
//     for (short i = 0; i < strlen(expresion); i++) {
//         if (expresion[i] == '1' || expresion[i] == '2' || expresion[i] == '3' || expresion[i] == '4' || expresion[i] == '5' || expresion[i] == '6' || expresion[i] == '7' || expresion[i] == '8' || expresion[i] == '9' || expresion[i] == '0') {
//             push(&nums, expresion[i]);
//         } else if (expresion[i] == '+' || expresion[i] == '-' || expresion[i] == '*' || expresion[i] == '/' || expresion[i] == '^') {
//             push(&exps, expresion[i]);
//         } else if (expresion[i] == '(' || expresion[i] == '[' || expresion[i] == '{') {
//             push (&parenthesis, expresion[i]);
//         } else {
//             printf("Not a valid expression\n");
//             return;
//         }
//
//         if (expresion[i] == ')' || expresion[i] == ']' || expresion[i] == '}') {
//             if (!validParenthesis(expresion[i], parenthesis)) {
//                 printf("Not a valid expression\n");
//                 return;
//             }
//
//
//             solveCurrentTwoNumExpresion();
//
//
//             char operator = pop(&exps);
//             char numDer = pop(&nums);
//             char numIzq = pop(&nums);
//
//             switch (operator) {
//                 case '+': push(&nums, numIzq + numDer);
//                 case '-': push(&nums, numIzq - numDer);
//                 case '*': push(&nums, numIzq * numIzq);
//                 case '/': push(&nums, numIzq /numDer);
//                 default: ;
//             }
//
//         }
//
//     }
// }
// //
// // int main() {
// //
// //     char *expression = "(2+2)*5";
// //     //
// //     solveSimpleMathExpresions(expression);
// //
// //     return 0;
// // }
//
