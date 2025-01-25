// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//
// struct Nodo {
//     char letra;
//     struct Nodo *izquierda;
//     struct Nodo *derecha;
// };
//
// struct Nodo* crearNodo(char letra) {
//     struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
//     if (nuevoNodo == NULL) {
//         fprintf(stderr, "Error al asignar memoria.\n");
//         exit(EXIT_FAILURE);
//     }
//     nuevoNodo->letra = letra;
//     nuevoNodo->izquierda = NULL;
//     nuevoNodo->derecha = NULL;
//     return nuevoNodo;
// }
//
// // Construir el árbol de Huffman según los códigos definidos
// struct Nodo* construirArbolHuffman() {
//     struct Nodo* nodoA = crearNodo('a'); // 001
//     struct Nodo* nodoB = crearNodo('b'); // 0000
//     struct Nodo* nodoC = crearNodo('c'); // 0001
//     struct Nodo* nodoD = crearNodo('d'); // 010
//     struct Nodo* nodoE = crearNodo('e'); // 011
//     struct Nodo* nodoF = crearNodo('f'); // 1
//
//     // Nivel más profundo para 'b' y 'c'
//     struct Nodo* nodo000 = crearNodo('\0'); // Nodo intermedio para 000
//     nodo000->izquierda = nodoB; // 0000
//     nodo000->derecha = nodoC;  // 0001
//
//     // Nodo para 'a' en 001
//     struct Nodo* nodo00 = crearNodo('\0'); // Nodo intermedio para 00
//     nodo00->izquierda = nodo000; // 000
//     nodo00->derecha = nodoA;     // 001
//
//     // Nodo para 'd' y 'e' en 010 y 011
//     struct Nodo* nodo01 = crearNodo('\0'); // Nodo intermedio para 01
//     nodo01->izquierda = nodoD; // 010
//     nodo01->derecha = nodoE;   // 011
//
//     // Nodo raíz para la parte '0' del árbol
//     struct Nodo* nodo0 = crearNodo('\0'); // Nodo intermedio para 0
//     nodo0->izquierda = nodo00; // 00
//     nodo0->derecha = nodo01;   // 01
//
//     // Nodo raíz final conectando '0' y '1'
//     struct Nodo* nodoRaiz = crearNodo('\0'); // Raíz del árbol
//     nodoRaiz->izquierda = nodo0; // 0
//     nodoRaiz->derecha = nodoF;  // 1
//
//     return nodoRaiz;
// }
//
// // Decodificar un código Huffman con logs detallados
// char decodificarCodigo(struct Nodo* raiz, const char* codigo) {
//     struct Nodo* actual = raiz;
//
//     printf("Inicio de la decodificación del código: %s\n", codigo);
//     printf("Nodo raíz inicial: %p (Letra: '%c')\n", (void*)actual, actual->letra == '\0' ? ' ' : actual->letra);
//
//     // Recorrer el árbol según el código Huffman
//     for (int i = 0; i < strlen(codigo); i++) {
//         printf("Paso %d: Leyendo bit '%c'\n", i + 1, codigo[i]);
//
//         if (codigo[i] == '0') {
//             actual = actual->izquierda;
//             printf("   -> Moviendo a la izquierda. Nodo actual: %p (Letra: '%c')\n",
//                    (void*)actual, (actual != NULL && actual->letra != '\0') ? actual->letra : ' ');
//         } else if (codigo[i] == '1') {
//             actual = actual->derecha;
//             printf("   -> Moviendo a la derecha. Nodo actual: %p (Letra: '%c')\n",
//                    (void*)actual, (actual != NULL && actual->letra != '\0') ? actual->letra : ' ');
//         } else {
//             printf("   -> Código inválido. Caracter no reconocido: '%c'\n", codigo[i]);
//             return '\0';
//         }
//
//         if (actual == NULL) {
//             printf("   -> Nodo actual es NULL. Código inválido.\n");
//             return '\0';
//         }
//     }
//
//     // Verificar si se llegó a una hoja válida
//     if (actual != NULL && actual->izquierda == NULL && actual->derecha == NULL) {
//         printf("   -> Nodo hoja encontrado. Letra: '%c'\n", actual->letra);
//         return actual->letra; // Retornar la letra correspondiente
//     }
//
//     printf("   -> No se alcanzó un nodo hoja válido. Código inválido.\n");
//     return '\0'; // Si no es una hoja válida, retornar inválido
// }
//
// char* codificarLetra(struct Nodo* raiz, char letra, char* codigo, int profundidad) {
//     if (raiz == NULL)
//         return NULL;
//
//     if (raiz->izquierda == NULL && raiz->derecha == NULL) {
//         if (raiz->letra == letra) {
//             codigo[profundidad] = '\0'; // Terminar la cadena
//             return strdup(codigo); // Retornar una copia del código
//         }
//         return NULL;
//     }
//
//     // Explorar la izquierda agregando '0'
//     codigo[profundidad] = '0';
//     char* izquierda = codificarLetra(raiz->izquierda, letra, codigo, profundidad + 1);
//     if (izquierda != NULL)
//         return izquierda;
//
//     // Explorar la derecha agregando '1'
//     codigo[profundidad] = '1';
//     char* derecha = codificarLetra(raiz->derecha, letra, codigo, profundidad + 1);
//     if (derecha != NULL)
//         return derecha;
//
//     return NULL;
// }
//
// // Función para codificar una cadena de texto a su código Huffman
// char* codificarTexto(struct Nodo* raiz, const char* texto) {
//     // Estimar el tamaño máximo del código resultante
//     // Cada caracter puede tener hasta 4 bits, más el carácter nulo
//     int maxTam = strlen(texto) * 5 + 1;
//     char* codigoFinal = (char*)malloc(maxTam * sizeof(char));
//     if (codigoFinal == NULL) {
//         fprintf(stderr, "Error al asignar memoria para el código final.\n");
//         exit(EXIT_FAILURE);
//     }
//     codigoFinal[0] = '\0'; // Inicializar cadena vacía
//
//     char buffer[20]; // Buffer para el código de cada letra
//     for (int i = 0; i < strlen(texto); i++) {
//         // Obtener el código de la letra actual
//         char* codigoLetra = codificarLetra(raiz, texto[i], buffer, 0);
//         if (codigoLetra == NULL) {
//             printf("Caracter '%c' no encontrado en el árbol de Huffman.\n", texto[i]);
//             free(codigoFinal);
//             return NULL;
//         }
//         // Concatenar el código al resultado final
//         strcat(codigoFinal, codigoLetra);
//         free(codigoLetra); // Liberar la cadena duplicada
//     }
//
//     return codigoFinal;
// }
//
// // Función para decodificar una cadena de bits completa
// char* decodificarMensaje(struct Nodo* raiz, const char* mensaje) {
//     int longitud = strlen(mensaje);
//     // Suponiendo que cada letra puede tener hasta 4 bits, el mensaje no puede tener más de longitud caracteres
//     char* texto = (char*)malloc((longitud + 1) * sizeof(char)); // Más que suficiente
//     if (texto == NULL) {
//         fprintf(stderr, "Error al asignar memoria para el texto decodificado.\n");
//         exit(EXIT_FAILURE);
//     }
//     texto[0] = '\0'; // Inicializar cadena vacía
//
//     struct Nodo* actual = raiz;
//     for (int i = 0; i < longitud; i++) {
//         if (mensaje[i] == '0') {
//             actual = actual->izquierda;
//         } else if (mensaje[i] == '1') {
//             actual = actual->derecha;
//         } else {
//             printf("Caracter inválido en el mensaje: '%c'. Solo se permiten '0' y '1'.\n", mensaje[i]);
//             free(texto);
//             return NULL;
//         }
//
//         if (actual == NULL) {
//             printf("Secuencia inválida en el mensaje en el bit %d.\n", i + 1);
//             free(texto);
//             return NULL;
//         }
//
//         // Si es una hoja, agregar la letra al texto y reiniciar la búsqueda desde la raíz
//         if (actual->izquierda == NULL && actual->derecha == NULL) {
//             int len = strlen(texto);
//             texto[len] = actual->letra;
//             texto[len + 1] = '\0';
//             actual = raiz;
//         }
//     }
//
//     // Verificar si terminamos en la raíz (es decir, no hay bits pendientes)
//     if (actual != raiz) {
//         printf("El mensaje termina en una secuencia incompleta.\n");
//         free(texto);
//         return NULL;
//     }
//
//     return texto;
// }
//
// // Liberar la memoria del árbol de Huffman
// void liberarArbol(struct Nodo* raiz) {
//     if (raiz == NULL)
//         return;
//     liberarArbol(raiz->izquierda);
//     liberarArbol(raiz->derecha);
//     free(raiz);
// }
//
// int main() {
//     struct Nodo* raiz = construirArbolHuffman();
//     int opcion;
//     char entrada[1000];
//     char* resultado = NULL;
//
//     while (1) {
//         printf("\n--- Árbol de Huffman ---\n");
//         printf("1. Codificar texto\n");
//         printf("2. Decodificar mensaje\n");
//         printf("3. Salir\n");
//         printf("Seleccione una opción: ");
//         if (scanf("%d", &opcion) != 1) {
//             // Limpiar entrada inválida
//             while (getchar() != '\n');
//             printf("Entrada inválida. Por favor, ingrese un número.\n");
//             continue;
//         }
//
//         // Limpiar el buffer de entrada
//         while (getchar() != '\n');
//
//         if (opcion == 1) {
//             // Codificar texto
//             printf("Ingrese el texto a codificar: ");
//             if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
//                 printf("Error al leer la entrada.\n");
//                 continue;
//             }
//             // Eliminar el salto de línea al final si existe
//             size_t len = strlen(entrada);
//             if (len > 0 && entrada[len - 1] == '\n') {
//                 entrada[len - 1] = '\0';
//             }
//
//             resultado = codificarTexto(raiz, entrada);
//             if (resultado != NULL) {
//                 printf("Texto codificado: %s\n", resultado);
//                 free(resultado);
//             }
//         } else if (opcion == 2) {
//             // Decodificar mensaje
//             printf("Ingrese el mensaje a decodificar (solo '0' y '1'): ");
//             if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
//                 printf("Error al leer la entrada.\n");
//                 continue;
//             }
//             // Eliminar el salto de línea al final si existe
//             size_t len = strlen(entrada);
//             if (len > 0 && entrada[len - 1] == '\n') {
//                 entrada[len - 1] = '\0';
//             }
//
//             resultado = decodificarMensaje(raiz, entrada);
//             if (resultado != NULL) {
//                 printf("Mensaje decodificado: %s\n", resultado);
//                 free(resultado);
//             }
//         } else if (opcion == 3) {
//             // Salir del programa
//             printf("Saliendo del programa.\n");
//             break;
//         } else {
//             printf("Opción inválida. Por favor, seleccione 1, 2 o 3.\n");
//         }
//     }
//
//     // Liberar la memoria del árbol
//     liberarArbol(raiz);
//     return 0;
// }