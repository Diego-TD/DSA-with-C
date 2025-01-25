//
// Created by Diego Torres Durante on 12/2/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
    char letra;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

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

struct Nodo* construirArbolHuffman() {
    struct Nodo* nodoA = crearNodo('a');
    struct Nodo* nodoB = crearNodo('b');
    struct Nodo* nodoC = crearNodo('c');
    struct Nodo* nodoD = crearNodo('d');
    struct Nodo* nodoE = crearNodo('e');
    struct Nodo* nodoF = crearNodo('f');

    struct Nodo* nodo000 = crearNodo('\0');
    nodo000->izquierda = nodoB;
    nodo000->derecha = nodoC;

    struct Nodo* nodo00 = crearNodo('\0');
    nodo00->izquierda = nodo000;
    nodo00->derecha = nodoA;

    struct Nodo* nodo01 = crearNodo('\0');
    nodo01->izquierda = nodoD;
    nodo01->derecha = nodoE;

    struct Nodo* nodo0 = crearNodo('\0');
    nodo0->izquierda = nodo00;
    nodo0->derecha = nodo01;

    struct Nodo* nodoRaiz = crearNodo('\0');
    nodoRaiz->izquierda = nodo0;
    nodoRaiz->derecha = nodoF;

    return nodoRaiz;
}

char* decodificarMensaje(struct Nodo* raiz, const char* mensaje) {
    int longitud = strlen(mensaje);
    char* texto = (char*)malloc((longitud + 1) * sizeof(char));
    if (!texto) {
        fprintf(stderr, "Error de memoria.\n");
        exit(EXIT_FAILURE);
    }
    texto[0] = '\0';
    struct Nodo* actual = raiz;
    for (int i = 0; i < longitud; i++) {
        if (mensaje[i] == '0') {
            actual = actual->izquierda;
        } else if (mensaje[i] == '1') {
            actual = actual->derecha;
        } else {
            free(texto);
            return NULL;
        }

        if (!actual) {
            free(texto);
            return NULL;
        }

        if (!actual->izquierda && !actual->derecha) {
            int len = strlen(texto);
            texto[len] = actual->letra;
            texto[len + 1] = '\0';
            actual = raiz;
        }
    }

    if (actual != raiz) {
        free(texto);
        return NULL;
    }

    return texto;
}

void liberarArbol(struct Nodo* raiz) {
    if (raiz) {
        liberarArbol(raiz->izquierda);
        liberarArbol(raiz->derecha);
        free(raiz);
    }
}

int main() {
    struct Nodo* raiz = construirArbolHuffman();
    const char* mensaje = "010011101100010010100010100110001001010001101100100000110000011";
    char* texto = decodificarMensaje(raiz, mensaje);
    if (texto) {
        printf("Mensaje decodificado: %s\n", texto);
        free(texto);
    } else {
        printf("El mensaje es inválido o contiene errores.\n");
    }
    liberarArbol(raiz);
    return 0;
}