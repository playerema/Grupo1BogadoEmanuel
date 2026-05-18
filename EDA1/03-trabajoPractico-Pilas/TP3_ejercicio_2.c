#include <stdbool.h>
#include <stdlib.h>
#include "tp_pilas.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

//  a.	Buscar una clave y determinar si existe en la Pila (sin perder la pila).
// Si la encuentra retorna true, caso contrario false
bool p_ej2_existeclave(Pila p, int clave) {

    if (p_es_vacia(p)) return false;

    Pila paux = p_crear();
    TipoElemento clave_buscar;
    bool encontrado = false;

    while (!p_es_vacia(p)) {

        clave_buscar = p_desapilar(p);

        if (clave == clave_buscar->clave) encontrado = true;

        p_apilar(paux, clave_buscar);
    }

    while (!p_es_vacia(paux)) {

        p_apilar(p, p_desapilar(paux));
    }

    return encontrado;
}

//  b.	Colocar en una posición ordinal determinada, recibida por parámetro, un nuevo elemento (Insertar un elemento nuevo).
// Retorna la nueva pila con el nuevo elemento, caso contrario la pila original recibida.
Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x) {

    if (p_es_llena(p)) return p;

    Pila paux = p_crear();
    Pila p_insertar = p_crear();
    int cantidad = 0;

    while (!p_es_vacia(p)) {

        p_apilar(paux, p_desapilar(p));
        cantidad++;
    }

    if (cantidad < posicionordinal) p_apilar(p_insertar, x);

    while (!p_es_vacia(paux)) {

        TipoElemento elem = p_desapilar(paux);
        p_apilar(p_insertar, elem);
        p_apilar(p, elem);
        
        if (cantidad == posicionordinal) p_apilar(p_insertar, x);

        cantidad--;
    }

    return p_insertar;
}

//  c.	Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la clave).
// retorna la nueva pila sin la clave, si la encuentra, sino retorna la misma pila que recibio.
Pila p_ej2_eliminarclave(Pila p, int clave) {

    if (p_es_vacia(p)) return p;

    Pila paux = p_crear();
    Pila p_borrar = p_crear();
    bool eliminado = false;
    
    while (!p_es_vacia(p)) {
        p_apilar(paux, p_desapilar(p));
    }

    while (!p_es_vacia(paux)) {

        TipoElemento elem = p_desapilar(paux);

        p_apilar(p, elem);

        if (!eliminado && elem->clave == clave) {

            eliminado = true;
            continue;
        }

        p_apilar(p_borrar, elem);
    }

    return p_borrar;
   
}

//  d.	Intercambiar los valores de 2 posiciones ordinales de la pila, por ejemplo la 2da con la 4ta.
// retorna la nueva pila con las posiciones cambiadas, siempre que sea posible hacerlo, caso contrario retorna la pila recibida.
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2) {

    if (p_es_vacia(p)) return p;

    Pila paux = p_crear();
    Pila p_inter = p_crear();
    int pos = 0;
    TipoElemento elem1 = NULL, elem2 = NULL;

    while(!p_es_vacia(p)) {
        
        TipoElemento elem = p_desapilar(p);

        if (pos + 1 == pos1) elem1 = elem;
        else if (pos + 1 == pos2) elem2 = elem;

        p_apilar(paux, elem);
        pos++;
    }

    if (elem1 == NULL || elem2 == NULL) {

        while(!p_es_vacia(paux)) {
            
            p_apilar(p, p_desapilar(paux));
        }

        return p;
    }

    int pos_aux = 1;

    while (!p_es_vacia(paux)) {

        TipoElemento elem = p_desapilar(paux);

        if (pos_aux == (pos - (pos1 - 1))) p_apilar(p_inter, elem2);
        else if (pos_aux == (pos - (pos2 - 1))) p_apilar(p_inter, elem1);
        else p_apilar(p_inter, elem);

        p_apilar(p, elem);

        pos_aux++;
    }

    return p_inter;

}

//  e.	Duplicar el contenido de una pila.
// retorna la nueva pila. Si esta vacia retorna otra vacia.
Pila p_ej2_duplicar(Pila p) {

    if (p_es_vacia(p)) {
        Pila p_nueva = p_crear();
        return p_nueva;
    };

    Pila paux = p_crear();
    Pila p_dupli = p_crear();

    while (!p_es_vacia(p)) {

        p_apilar(paux, p_desapilar(p));
    }

    while (!p_es_vacia(paux)) {

        TipoElemento elem = p_desapilar(paux);

        p_apilar(p_dupli, te_crear(elem->clave * 2));
        p_apilar(p, elem);
    }

    return p_dupli;
}

//  f.	Contar los elementos de la pila.
// retorna la cantidad de elementos de la pila. Si esta vacia retorna 0 (cero).
int p_ej2_cantidadelementos(Pila p) {

    Pila paux = p_crear();
    int conteo = 0;

    while (!p_es_vacia(p)) {

        p_apilar(paux, p_desapilar(p));
        conteo++;
    }

    while(!p_es_vacia(paux)) {

        p_apilar(p, p_desapilar(paux));
    }

    return conteo;

}