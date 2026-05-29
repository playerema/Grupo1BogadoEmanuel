#include "tp_pilas.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

/**
 5.	Invertir el contenido de una pila sin destruir la pila original.
	Se debe retornar la nueva pila invertida y la original no se debe perder.
	Determinar la complejidad algorítmica de la solución.
 */

// O(n)
Pila  p_ej5_invertir(Pila p) {

    Pila paux = p_crear();
    Pila p_invertida = p_crear();

    while (!p_es_vacia(p)) {

        TipoElemento e = p_desapilar(p);

        p_apilar(paux, e);
        p_apilar(p_invertida, e);
    }

    while(!p_es_vacia(paux)) {

        p_apilar(p, p_desapilar(paux));
    }

    return p_invertida;
}