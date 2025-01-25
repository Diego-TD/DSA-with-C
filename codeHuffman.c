#include <stdio.h>
#include <stdlib.h>

// Definición del nodo del árbol
struct Nodo {
    char letra;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

// Crear un nuevo nodo
struct Nodo* crearNodo(char letra) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (!nuevoNodo) {
        fprintf(stderr, "Error de memoria.\n");
        exit(EXIT_FAILURE);
    }
    nuevoNodo->letra = letra;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

// Construir el árbol de Huffman según los códigos definidos
struct Nodo* construirArbolHuffman() {
    struct Nodo* nodoA = crearNodo('a'); // 001
    struct Nodo* nodoB = crearNodo('b'); // 0000
    struct Nodo* nodoC = crearNodo('c'); // 0001
    struct Nodo* nodoD = crearNodo('d'); // 010
    struct Nodo* nodoE = crearNodo('e'); // 011
    struct Nodo* nodoF = crearNodo('f'); // 1

    struct Nodo* nodo000 = crearNodo('\0');
    nodo000->izquierda = nodoB; // 0000
    nodo000->derecha = nodoC;   // 0001

    struct Nodo* nodo00 = crearNodo('\0');
    nodo00->izquierda = nodo000; // 000
    nodo00->derecha = nodoA;     // 001

    struct Nodo* nodo01 = crearNodo('\0');
    nodo01->izquierda = nodoD; // 010
    nodo01->derecha = nodoE;   // 011

    struct Nodo* nodo0 = crearNodo('\0');
    nodo0->izquierda = nodo00; // 00
    nodo0->derecha = nodo01;   // 01

    struct Nodo* nodoRaiz = crearNodo('\0');
    nodoRaiz->izquierda = nodo0; // 0
    nodoRaiz->derecha = nodoF;   // 1

    return nodoRaiz;
}

// Función recursiva para encontrar el código de una letra
int encontrarCodigo(struct Nodo* raiz, char letra, char* codigo, int profundidad) {
    if (raiz == NULL)
        return 0;

    // Si es una hoja
    if (raiz->izquierda == NULL && raiz->derecha == NULL) {
        if (raiz->letra == letra) {
            codigo[profundidad] = '\0';
            return 1;
        }
        return 0;
    }

    // Buscar en la izquierda agregando '0'
    codigo[profundidad] = '0';
    if (encontrarCodigo(raiz->izquierda, letra, codigo, profundidad + 1))
        return 1;

    // Buscar en la derecha agregando '1'
    codigo[profundidad] = '1';
    if (encontrarCodigo(raiz->derecha, letra, codigo, profundidad + 1))
        return 1;

    return 0;
}

// Liberar la memoria del árbol
void liberarArbol(struct Nodo* raiz) {
    if (raiz) {
        liberarArbol(raiz->izquierda);
        liberarArbol(raiz->derecha);
        free(raiz);
    }
}

int main() {
    struct Nodo* raiz = construirArbolHuffman();
    char letras[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int numLetras = sizeof(letras) / sizeof(letras[0]);
    char codigo[100]; // Suficiente para almacenar el código

    printf("Test Cases para Todas las Letras\n");
    for (int i = 0; i < numLetras; i++) {
        char letra = letras[i];
        if (encontrarCodigo(raiz, letra, codigo, 0)) {
            printf("La letra '%c' tiene el código Huffman: %s\n", letra, codigo);
        } else {
            printf("La letra '%c' no se encuentra en el árbol de Huffman.\n", letra);
        }
    }

    liberarArbol(raiz);
    return 0;
}