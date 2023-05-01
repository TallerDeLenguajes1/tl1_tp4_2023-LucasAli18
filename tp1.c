#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int valor;
    struct Nodo *siguiente;
};

void agregar_al_principio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo_nodo = (struct Nodo *) malloc(sizeof(struct Nodo));
    nuevo_nodo->valor = valor;
    nuevo_nodo->siguiente = *cabeza;
    *cabeza = nuevo_nodo;
}

void imprimir_lista(struct Nodo *nodo) {
    while (nodo != NULL) {
        printf("%d ", nodo->valor);
        nodo = nodo->siguiente;
    }
    printf("\n");
}

int main() {
    struct Nodo *cabeza = NULL;

    // Agregar 3 nodos a la lista
    agregar_al_principio(&cabeza, 3);
    agregar_al_principio(&cabeza, 2);
    agregar_al_principio(&cabeza, 1);

    // Imprimir la lista
    printf("Lista: ");
    imprimir_lista(cabeza);

    return 0;
}
