#include <stdbool.h>
#include "tp_colas.h"
#include "../libs/colas/headers/colas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

/**
3.	Dadas dos colas, determinar si sus contenidos son iguales tanto en posición como en datos (solo comparar por la clave),
	sin destruirlas. Utilizar para la resolución del problema una sola cola auxiliar.
 */
// retorna true si son exactamente iguales, caso contrario retorna false.
bool c_ej3_iguales(Cola c1, Cola c2) {

    if (c_es_vacia(c1) && c_es_vacia(c2)) return true;
    if (c_es_vacia(c1) != c_es_vacia(c2)) return false;

    Cola caux = c_crear();

    bool iguales = true;

    while(!c_es_vacia(c1) && !c_es_vacia(c2) && iguales) {

        TipoElemento e1 = c_desencolar(c1);
        TipoElemento e2 = c_desencolar(c2);

        if (e1->clave != e2->clave) {
            iguales = false;

            c_encolar(c1, e1);
            c_encolar(c2, e2);
        }

        if (iguales) c_encolar(caux, e1); 
    }

    if (c_es_vacia(c1) != c_es_vacia(c2)) iguales = false;

    while (!c_es_vacia(caux)) {

        TipoElemento e = c_desencolar(caux);

        c_encolar(c1, e);
        c_encolar(c2, e);
    }

    return iguales;
}