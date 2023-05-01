#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura para un nodo de la lista
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

// Función para insertar un nuevo nodo al final de la lista
void insertarAlFinal(struct Nodo **cabeza, int dato) {
    // Crear un nuevo nodo
    struct Nodo *nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    // Si la lista está vacía, el nuevo nodo se convierte en la cabeza
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        return;
    }

    // Recorrer la lista hasta el último nodo
    struct Nodo *ultimoNodo = *cabeza;
    while (ultimoNodo->siguiente != NULL) {
        ultimoNodo = ultimoNodo->siguiente;
    }

    // Insertar el nuevo nodo al final de la lista
    ultimoNodo->siguiente = nuevoNodo;
}

// Función para imprimir los datos de todos los nodos de la lista
void imprimirLista(struct Nodo *cabeza) {
    printf("Elementos de la lista:\n");
    while (cabeza != NULL) {
        printf("%d ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("\n");
}

int main() {
    struct Nodo *cabeza = NULL;

    // Insertar elementos en la lista
    insertarAlFinal(&cabeza, 10);
    insertarAlFinal(&cabeza, 20);
    insertarAlFinal(&cabeza, 30);

    // Imprimir la lista
    imprimirLista(cabeza);

    return 0;
}
