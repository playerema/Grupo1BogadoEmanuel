#include <stdbool.h>
#include <stdlib.h>
#include "tp_pilas.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

/**
 3.	Dadas dos pilas, determinar si sus contenidos son exactamente iguales (solo por la clave), sin destruirlas.
	Utilizar para la resolución del problema una única pila auxiliar.
	Determinar la complejidad algorítmica de la solución.
 */
// retorna true si son exactamente iguales, caso contrario retorna false
bool p_ej3_iguales(Pila p1, Pila p2) {

    if (p_es_vacia(p1) && p_es_vacia(p2)) return true;
    if (p_es_vacia(p1) != p_es_vacia(p2)) return false;

    Pila paux = p_crear();

    bool iguales = true;

    while (!p_es_vacia(p1) && !p_es_vacia(p2) && iguales) {

        TipoElemento e1 = p_desapilar(p1);
        TipoElemento e2 = p_desapilar(p2);

        if (e1->clave != e2->clave) {
            iguales = false;

            p_apilar(p1, e1);
            p_apilar(p2, e2);
        } 

        if (iguales) {
            p_apilar(paux, e1);
        }

    }

    if (p_es_vacia(p1) != p_es_vacia(p2)) return false;

    while(!p_es_vacia(paux)) {

        TipoElemento e = p_desapilar(paux);

        p_apilar(p1, e);
        p_apilar(p2, e);
    }

    return iguales;

}