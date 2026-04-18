#include "../headers/listas.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../tipoElemento/headers/tipo_elemento.h"

static const int TAMANIO_MAXIMO = 100;

struct nodo {
    TipoElemento valores;
    struct nodo *siguiente;
};

struct ListaRep {
    struct nodo *inicio;
    int cantidad;
};

struct IteradorRep {
    Lista lista;
    struct nodo* posicionActual;
};


//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
// Rutinas del TAD
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

Lista l_crear() {
    Lista nueva_lista = (Lista) malloc(sizeof(struct ListaRep));
    nueva_lista->inicio = NULL;
    nueva_lista->cantidad = 0;
    return nueva_lista;
}


bool l_es_vacia(Lista lista) {
    return (lista->cantidad == 0);
}


bool l_es_llena(Lista lista) {
    return (lista->cantidad == TAMANIO_MAXIMO);
}


int l_longitud(Lista lista) {
    return lista->cantidad;
}


bool l_agregar(Lista lista, TipoElemento elemento) {
    if (l_es_llena(lista)) return false;

    struct nodo *n = malloc(sizeof (struct nodo));
    n->valores = elemento;
    n->siguiente = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = n;
    } else {

        struct nodo *ultimo = lista->inicio;

        while (ultimo->siguiente != NULL) {
            ultimo = ultimo->siguiente;
        }

        ultimo->siguiente = n;
    }
    lista->cantidad++;

    return true;
}


bool l_borrar(Lista lista, int clave) {
    if (l_es_vacia(lista)) return false;

    bool borre = false;

    struct nodo *actual = lista->inicio;
    struct nodo *anterior = NULL;

    while (actual != NULL) {

        if (actual->valores->clave == clave) {

            struct nodo *borrar = actual;

            if (anterior == NULL) {
                lista->inicio = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }

            actual = actual->siguiente;
            free(borrar);

            lista->cantidad--;
            borre = true;
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    return borre;

}


TipoElemento l_buscar(Lista lista, int clave) {

    struct nodo *actual = lista->inicio;

    while (actual != NULL) {
        if (actual->valores->clave == clave) {
            return actual->valores;
        }
        actual = actual->siguiente;
    }
    return NULL;
}


bool l_insertar(Lista lista, TipoElemento elemento, int pos) {
    if (l_es_llena(lista)) return false;
    if (pos <= 0 || pos > l_longitud(lista) + 1) return false;

    struct nodo *n = malloc(sizeof(struct nodo));
    n->valores = elemento;
    n->siguiente = NULL;

    struct nodo *actual = lista->inicio;
    struct nodo *siguiente = actual->siguiente;

    if (pos == 1) {
        n->siguiente = actual;
        lista->inicio = n;
        lista->cantidad++;
    } else if (pos == l_longitud(lista) + 1) {
        l_agregar(lista, elemento);
    } else {

        for(int i = 1;i <= l_longitud(lista); i++){

            if(i == pos - 1){
                n->siguiente = siguiente;
                actual->siguiente = n;
            
                i = l_longitud(lista);
            }

            siguiente = siguiente->siguiente;
            actual = actual->siguiente;

        }
        lista->cantidad++;
    }

    return true;
}


bool l_eliminar(Lista lista, int pos) {

    if (l_es_vacia(lista)) return false;
    if (pos <= 0 || pos >= l_longitud(lista) + 1) return false;

    struct nodo *actual = lista->inicio;
    struct nodo *siguiente = actual->siguiente;

    if (pos == 1) {
        lista->inicio = lista->inicio->siguiente;
        lista->cantidad--;
    } else {

        for (int i = 1; i < l_longitud(lista); i++) {

            if (i == pos - 1) {
                actual->siguiente = siguiente->siguiente;
                lista->cantidad--;
                return true;
            }

            actual = actual->siguiente;
            siguiente = siguiente->siguiente;
        }
    }
}


TipoElemento l_recuperar(Lista lista, int pos) {
    if (pos <= 0 || pos >= l_longitud(lista) + 1) return NULL;

    struct nodo *actual = lista->inicio;

    for (int i = 1; i < pos; i++) {
        actual = actual->siguiente;
    }

    return actual->valores;
}


void l_mostrar(Lista lista) {
    printf("Contenido de la lista: ");

    struct nodo *actual = lista->inicio;
    for (int i = 0; i < lista->cantidad; i++) {
        printf("%d ", actual->valores->clave);
        actual = actual->siguiente;
    }
    printf("\n");
}


//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
// Rutinas del Iterador
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
Iterador iterador(Lista lista) {
    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
    iter->lista = lista;
    iter->posicionActual = lista->inicio;
    return iter;
}


bool hay_siguiente(Iterador iterador) {
    return iterador->posicionActual->siguiente != NULL;
}

TipoElemento siguiente(Iterador iterador) {
    if (iterador->posicionActual->siguiente != NULL) {

        TipoElemento elemento = iterador->posicionActual->valores;
        iterador->posicionActual = iterador->posicionActual->siguiente;
        return elemento;

    } else {
        return NULL;
    }
}