// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
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
// void isPalindrome(char palindrome[]) {
//     Stack s;
//     initStack(&s);
//     int length = strlen(palindrome);
//
//     char cleanStr[MAX];
//     int cleanIndex = 0;
//
//     for (int i = 0; i < length; i++) {
//         if (isalnum(palindrome[i])) {
//             cleanStr[cleanIndex++] = tolower(palindrome[i]);
//         }
//     }
//     cleanStr[cleanIndex] = '\0';
//
//     for (int i = 0; i < cleanIndex; i++) {
//         push(&s, cleanStr[i]);
//     }
//
//     for (int i = 0; i < cleanIndex; i++) {
//         if (pop(&s) != cleanStr[i]) {
//             printf("La frase no es un palíndromo.\n");
//             return;
//         }
//     }
//
//     printf("La frase es un palíndromo.\n");
// }
//
// int precedence(char operator) {
//     switch (operator) {
//         case '+':
//         case '-':
//             return 1;
//         case '*':
//         case '/':
//             return 2;
//         default:
//             return 0;
//     }
// }
//
// int isOperator(char ch) {
//     return ch == '+' || ch == '-' || ch == '*' || ch == '/';
// }
//
// void infixToPostfix(char infix[], char postfix[]) {
//     Stack s;
//     initStack(&s);
//     int postfixIndex = 0;
//
//     for (int i = 0; i < strlen(infix); i++) {
//         char token = infix[i];
//
//         if (isalnum(token)) {
//             postfix[postfixIndex++] = token;
//         } else if (token == '(' || token == '{' || token == '[') {
//             push(&s, token);
//         } else if (token == ')' || token == '}' || token == ']') {
//             while (!isEmpty(&s) && peek(&s) != '(' && peek(&s) != '{' && peek(&s) != '[') {
//                 postfix[postfixIndex++] = pop(&s);
//             }
//             pop(&s);
//         } else if (isOperator(token)) {
//             while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(token)) {
//                 postfix[postfixIndex++] = pop(&s);
//             }
//             push(&s, token);
//         }
//     }
//
//     while (!isEmpty(&s)) {
//         postfix[postfixIndex++] = pop(&s);
//     }
//
//     postfix[postfixIndex] = '\0';
// }
//
// int solvePostfix(char postfix[]) {
//     Stack s;
//     initStack(&s);
//
//     for (int i = 0; i < strlen(postfix); i++) {
//         char token = postfix[i];
//
//         if (isdigit(token)) {
//             push(&s, token - '0');
//         } else if (isOperator(token)) {
//             int op2 = pop(&s);
//             int op1 = pop(&s);
//             int result;
//
//             switch (token) {
//                 case '+': result = op1 + op2; break;
//                 case '-': result = op1 - op2; break;
//                 case '*': result = op1 * op2; break;
//                 case '/': result = op1 / op2; break;
//             }
//
//             push(&s, result);
//         }
//     }
//
//     return pop(&s);
// }
//
// // int main() {
// //     char palindrome[] = "Anita lava la tina";
// //     printf("Verificando si \"%s\" es un palíndromo:\n", palindrome);
// //     isPalindrome(palindrome);
// //
// //     char palindrome2[] = "Aníta lava la tina";
// //     printf("Verificando si \"%s\" es un palíndromo:\n", palindrome2);
// //     isPalindrome(palindrome);
// //
// //
// //     // Ejemplo para convertir expresión infija a postfija y resolverla
// //     char infix1[] = "(6*8)+(2*3)";
// //     char postfix1[MAX];
// //
// //     printf("\nConvertir la expresión infija \"%s\" a postfija:\n", infix1);
// //     infixToPostfix(infix1, postfix1);
// //     printf("Expresión postfija: %s\n", postfix1);
// //
// //     int result1 = solvePostfix(postfix1);
// //     printf("Resultado de la expresión postfija: %d\n", result1);
// //
// //     char infix2[] = "20*8-9/3+3*3";
// //     char postfix2[MAX];
// //
// //     printf("\nConvertir la expresión infija \"%s\" a postfija:\n", infix2);
// //     infixToPostfix(infix2, postfix2);
// //     printf("Expresión postfija: %s\n", postfix2);
// //
// //     int result2 = solvePostfix(postfix2);
// //     printf("Resultado de la expresión postfija: %d\n", result2);
// //
// //     return 0;
// // }