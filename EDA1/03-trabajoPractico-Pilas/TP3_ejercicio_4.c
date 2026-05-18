#include <stdlib.h>
#include <stdio.h>
#include "tp_pilas.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

/**
 4.	Construir un algoritmo que, utilizando el TAD Pila, permita convertir un número decimal pasado como parámetro,
	a su correspondiente valor expresado en una base de 2 a 16 (hexadecimal).
	Determinar la complejidad algorítmica de la solución.
 */
// retorna el valor cambiado de base como un string (char*).  Si la base no esta entre 2 y 16 retorno el mismo numero recibido como string (char*).
char* p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase); {

    if (nrootrabase < 2 || nrootrabase > 16) {
        char* res = malloc(20);
        sprintf(res, "%d", nrobasedecimal);
        return res;
    }

    Pila p = p_crear();

    if (nrobasedecimal == 0) {
        char* res = malloc(2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }

    while (n > 0) {
        int resto = nrobasedecimal % nrootrabase;

        TipoElemento e = te_crear(resto);
        p_apilar(p, e);

        nrobasedecimal = nrobasedecimal / nrootrabase;
    }

    char* res = malloc(50);
    int i = 0;

    while (!p_es_vacia(p)) {

        TipoElemento e = p_desapilar(p);

        int clave = e->clave;

        if (clave < 10) {
            res[i++] = '0' + clave;
        } else {
            res[i++] = 'A' + (clave - 10);
        }
    }

    res[i] = '\0';

    return res;
} // O(long n)
