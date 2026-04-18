#include "../headers/listas.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../tipoElemento/headers/tipo_elemento.h"

#define TAMANIO_MAXIMO 100
#define FIN -1

struct nodo {
    TipoElemento valores;
    int siguiente;
};

struct ListaRep {
    struct nodo datos[TAMANIO_MAXIMO];
    int inicio;
    int cantidad;
};

struct IteradorRep {
    Lista lista;
    int posicionActual;
};


//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
// Rutinas del TAD
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

Lista l_crear() {
    Lista nueva_lista = (Lista) malloc(sizeof(struct ListaRep));
    nueva_lista->cantidad = 0;
    nueva_lista->inicio = FIN;
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

    // variable que apunte al espacio despues del ultimo elemento
    int nuevo = lista->cantidad; 

    // ingresamos el elemento en el array
    lista->datos[nuevo].valores = elemento;
    lista->datos[nuevo].siguiente = FIN;
    
    // si no hay elementos
    if (lista->inicio == FIN) lista->inicio = nuevo;
    else {

        // si hay elementos recorremos hasta encontrar FIN en la variable "siguiente" de cada nodo.
        int actual = lista->inicio;

        while (lista->datos[actual].siguiente != FIN) {
            actual = lista->datos[actual].siguiente;
        }

        lista->datos[actual].siguiente = nuevo;
    }

    lista->cantidad++;
    return true;

}


bool l_borrar(Lista lista, int clave) {
    if (l_es_vacia(lista)) return false;

    // variables de cursor actual y anterior
    int actual = lista->inicio;
    int anterior = FIN;

    bool borre = false;

    // recorrer lista hasta que "actual" sea igual a FIN
    while (actual != FIN) {

        if (lista->datos[actual].valores->clave == clave) {

            // si es el primer elemento
            if (anterior == FIN) {
                lista->inicio = lista->datos[actual].siguiente;
            } else {
                lista->datos[anterior].siguiente = lista->datos[actual].siguiente;
            }

            actual = lista->datos[actual].siguiente;
            lista->cantidad--;
            borre = true;
        } else {
            anterior = actual;
            actual = lista->datos[actual].siguiente;
        }
    }

    return borre;
}


TipoElemento l_buscar(Lista lista, int clave) {
    if (l_es_vacia(lista)) return NULL;

    int cursor = lista->inicio;

    while (cursor != FIN) {

        if (lista->datos[cursor].valores->clave == clave) {
            return lista->datos[cursor].valores;
        }
        cursor = lista->datos[cursor].siguiente;
    }
    return NULL;
}


bool l_insertar(Lista lista, TipoElemento elemento, int pos) {

    if (l_es_llena(lista)) return false;
    if (pos <= 0 || pos > lista->cantidad + 1) return false;

    int nuevo = lista->cantidad;

    lista->datos[nuevo].valores = elemento;

    if (pos == 1) { // insertar al inicio
        lista->datos[nuevo].siguiente = lista->inicio;
        lista->inicio = nuevo;
        lista->cantidad++;
        return true;

    } else if (pos == l_longitud(lista) + 1) { // insertar al final
        return l_agregar(lista, elemento);
    }

    // insertar en el medio
    int actual = lista->inicio;

    // recorrer los nodos hasta quedar un espacio antes del pos
    for (int i = 1; i < pos - 1; i++) {
        actual = lista->datos[actual].siguiente;
    }

    lista->datos[nuevo].siguiente = lista->datos[actual].siguiente; // agregamos el siguiente nodo al nodo insertado
    lista->datos[actual].siguiente = nuevo; // agregamos al anterior nodo la direccion del nodo insertado

    lista->cantidad++;

    return true;
}


bool l_eliminar(Lista lista, int pos) {

    if (l_es_vacia(lista)) return false;
    if (pos <= 0 || pos >= l_longitud(lista) + 1) return false;

    int actual = lista->inicio;
    int siguiente = lista->datos[actual].siguiente;

    if (pos == 1) {
        lista->inicio = lista->datos[lista->inicio].siguiente;
        lista->cantidad--;
        return true;
    } else {

        for (int i = 1; i < l_longitud(lista); i++) {

            if (i == pos - 1) {

                lista->datos[actual].siguiente = lista->datos[siguiente].siguiente;
                lista->cantidad--;
                return true;
            }

            actual = lista->datos[actual].siguiente;
            siguiente = lista->datos[siguiente].siguiente;
        }
    }

    return false;
}


TipoElemento l_recuperar(Lista lista, int pos) {

    if (l_es_vacia(lista)) return NULL;
    if (pos <= 0 || pos > l_longitud(lista)) return NULL;

    int actual = lista->inicio;

    for(int i = 1; i < pos; i++) {
        actual = lista->datos[actual].siguiente;
    }

    return lista->datos[actual].valores;
}


void l_mostrar(Lista lista) {
    printf("Contenido de la lista: ");

    int actual = lista->inicio;
    for (int i = 0; i < lista->cantidad; i++) {
        printf("%d ", lista->datos[actual].valores->clave);
        actual = lista->datos[actual].siguiente;
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
    return iterador->posicionActual != FIN;
}


TipoElemento siguiente(Iterador iterador) {
    if (iterador->posicionActual != FIN) {

        TipoElemento elemento = iterador->lista->datos[iterador->posicionActual].valores;
        iterador->posicionActual = iterador->lista->datos[iterador->posicionActual].siguiente;
        return elemento;
    }
    else {
        return NULL;
    }
}
