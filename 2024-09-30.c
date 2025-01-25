#include <stdbool.h>
#include <stdio.h>
//
// Created by Diego Torres Durante on 9/30/24.
//

// O(n) ingresar arreglo de n numeros, imprimir promedio



//Invertir arreglo y obtener media

// ordenar arreglo < o(n^2)





bool isPalindrome() {
    return false;
}











//
int rFibonacci_aux(int n, int a,int b) {
    if (a == 0) {
        return 0;
    }
    if (b == 1) {
        return 1;
    }
    if (n == 0) {
        return a;
    }
    a += b;
    rFibonacci_aux(n-1,a,b);
}

void recursiveFibonacci(int limit) {
    printf("%d" ,rFibonacci_aux(limit, 0, 0));
    return;
}

//
// void main() {
//     //recursiveFibonacci(1000);
//     recursiveFibonacci(10);
// }









// Operaciones sobre matrices
// + - / * de matrices
void juegoDeAdivinanzas() {

}


// Dado un numero determinar si es impar y primo, o
