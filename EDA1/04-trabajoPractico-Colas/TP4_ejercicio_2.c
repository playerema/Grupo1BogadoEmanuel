#include <stdbool.h>
#include "tp_colas.h"
#include "../libs/colas/headers/colas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

//  a.	Informar si un elemento dado se encuentra en la cola.
// Si la encuentra retorna true, caso contrario false
bool c_ej2_existeclave(Cola c, int clave) {

    if (c_es_vacia(c)) return false;

    Cola caux = c_crear();
    bool encontrado = false;

    while (!c_es_vacia(c) && !encontrado) {

        TipoElemento elem = c_desencolar(c);
        c_encolar(caux, elem);

        if (elem->clave == clave) encontrado = true;
    }

    while (!c_es_vacia(caux)) c_encolar(c, c_desencolar(caux));

    return encontrado;
}

//  b.	Agregar un nuevo elemento en una posición dada (colarse).
// Retorna la nueva cola con el elemento insertado, caso contrario la cola original recibida.
Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X) {

    if (c_es_llena(c)) return c;

    int pos = 1;
    Cola caux = c_crear();
    Cola cr = c_crear();

    while (!c_es_vacia(c)) {

        TipoElemento elem = c_desencolar(c);

        c_encolar(caux, elem);

        if (pos == posicionordinal) c_encolar(cr, X);
        c_encolar(cr, elem);

        pos++;
    }

    if (pos == posicionordinal) c_encolar(cr, X);

    while (!c_es_vacia(caux)) c_encolar(c, c_desencolar(caux));

    return cr;
    
}

//  c.	Dado un elemento sacarlo de la cola todas las veces que aparezca.
// Retorna la nueva cola sin el/los elemento/s, caso contrario la cola original recibida.
Cola c_ej2_sacarelemento(Cola c, int clave) {

    if (c_es_vacia(c)) return c;

    Cola caux = c_crear(), cr = c_crear();

    while (!c_es_vacia(c)) {

        TipoElemento elem = c_desencolar(c);
        c_encolar(caux, elem);

        if (elem->clave != clave) c_encolar(cr, elem);
    }

    while (!c_es_vacia(caux)) c_encolar(c, c_desencolar(caux));

    return cr;
}

//  d.	Contar los elementos de la cola.
// Retorna la cantidad de elementos de la cola, o 0 (cero) si esta vacia.
int c_ej2_contarelementos(Cola c) {

    if (c_es_vacia(c)) return 0;

    int contador = 0;
    Cola caux = c_crear();

    while (!c_es_vacia(c)) {

        c_encolar(caux, c_desencolar(c));
        contador++;
    }

    while (!c_es_vacia(caux)) c_encolar(c, c_desencolar(caux));

    return contador;
}

//  e.	Realizar una función que realice una copia de una cola.
// Retorna la cola copia tal cual la original, no debe perserse la original.  Si es vacia retorna vacia.
Cola c_ej2_copiar(Cola c) {

    if (c_es_vacia(c)) return c_crear();

    Cola caux = c_crear(), cr = c_crear();

    while (!c_es_vacia(c)) {

        TipoElemento elem = c_desencolar(c);

        c_encolar(caux, elem);
        c_encolar(cr, elem);
    }

    while (!c_es_vacia(caux)) c_encolar(c, c_desencolar(caux));

    return cr;
}

//  f.	Invertir el contenido de una cola sin destruir la cola original.
// Retorna la cola al reves (invertida), no debe perserse la original. Si es vacia retorna vacia.
Cola c_ej2_invertir(Cola c) {

    if (c_es_vacia(c)) return c_crear();

    Cola caux = c_crear(), cr = c_crear(), cr_aux = c_crear(), cr_aux_2 = c_crear();

    while (!c_es_vacia(c)) {

        TipoElemento elem = c_desencolar(c);

        c_encolar(caux, elem);
        c_encolar(cr_aux, elem);
    }

    while (!c_es_vacia(cr_aux)) {

        TipoElemento elem = c_desencolar(cr_aux);

        if (!c_es_vacia(cr_aux)) c_encolar(cr_aux_2, elem);
        else {
            c_encolar(cr, elem);

            while (!c_es_vacia(cr_aux_2)) c_encolar(cr_aux, c_desencolar(cr_aux_2));
        }

    }

    while (!c_es_vacia(caux)) c_encolar(c, c_desencolar(caux));

    return cr;
}
