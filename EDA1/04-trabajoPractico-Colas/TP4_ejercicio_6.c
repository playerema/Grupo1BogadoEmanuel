#include "tp_colas.h"
#include "../libs/colas/headers/colas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/pilas/headers/pilas.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
6.	Dada una pila y una cola generada con valores al azar retornar en una lista todos los valores comunes a ambas
	y en qué posición ordinal se encontró cada uno en su estructura.  
	Si existe mas de una vez la primer posicion encontrada, se retornará cada ocurrencia.
	No se deben destruir las estructuras originales.
	Ejemplo: si “P” = (2,5,8,19,3,4,5) y “C” = (4, 18, 12, 5, 4, 6) 
	la lista tendría L = (5:2:4, 4:6:1, 4:6:5, 5:7:4, ).
 */
// retornar una lista con los valores comunes segun las especificaciones del ejercicio.
// Si no existen valores comunes retornar la lista vacia.
Lista c_ej6_comunesapilaycola(Pila p, Cola c) {

    if (c_es_vacia(c) || p_es_vacia(p)) return l_crear();

    Cola caux = c_crear(); Pila paux = p_crear(); 
    
    Cola cr = c_crear(); Pila pr = p_crear(); Lista lr = l_crear();
    Cola cr_aux = c_crear(); Pila pr_aux = p_crear();

    while (!c_es_vacia(c)) {

        TipoElemento e = c_desencolar(c);

        c_encolar(cr, e);
        c_encolar(caux, e);
    }

    while (!p_es_vacia(p)) {

        TipoElemento e = p_desapilar(p);

        p_apilar(pr, e);
        p_apilar(paux, e);
    }

    int c_base = 1;

    while (!c_es_vacia(cr)) {

        int c_cont = c_base;
        int p_cont = 0;
        bool seguir = true;

        TipoElemento c_e = c_desencolar(cr);

        while (!p_es_vacia(pr) && seguir) {

            TipoElemento p_e = p_desapilar(pr);
            p_cont++;

            if (c_e->clave == p_e->clave) {

                char *text = malloc(32);
                sprintf(text, "%d:%d:%d", c_e->clave, c_cont, p_cont);

                l_agregar(lr, te_crear_con_valor(c_e->clave, text));
                seguir = false;
            }

            p_apilar(pr_aux, p_e);

        }

        while(!p_es_vacia(pr_aux)) p_apilar(pr, p_desapilar(pr_aux));
        c_base++;
    }

    return lr;
}