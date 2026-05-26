#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp_pilas.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

/**
8.	Dada una pila con valores repetidos, se desea obtener una nueva pila con todos los valores (sin repetición) y la cantidad de veces que aparecen.
	No debe perderse la pila original.  El proceso recibe la pila con las repeticiones  y retorna una nueva pila.
	Determinar la complejidad algorítmica de la solución.
 */
// retornar la nueva pila con las claves unicas (no deben existir repetidas) y por cada una la cantidad de veces que aparecia en la Pila recibida por parametro
// Si la pila estavacia retorna pila vacia.

Pila p_ej8_sacarrepetidos(Pila p) {
    if (p_es_vacia(p)) {
        return p_crear();
    } 

    Pila resultado = p_crear();   
    Pila auxOriginal = p_crear(); 
    Pila temp = p_crear();        
    
    while (!p_es_vacia(p)) {  
        TipoElemento elem = p_desapilar(p); 
        int claveActual = elem -> clave; 
        bool existe = false;

        
        while (!p_es_vacia(resultado)) {
            TipoElemento resu = p_desapilar(resultado); 
            if (resu -> clave == claveActual) {
                existe = true;
                int *frecu = (int*)resu -> valor;
                (*frecu)++;
                p_apilar(temp, resu); 
            } else {
                p_apilar(temp, resu);
            }
        }

        while (!p_es_vacia(temp)) {
            p_apilar(resultado, p_desapilar(temp));
        }

        if (!existe) {
            int *frecInicial = (int*)malloc(sizeof(int));
            *frecInicial = 1;
            TipoElemento nuevo = te_crear_con_valor(claveActual, frecInicial); 
            p_apilar(resultado, nuevo); 
        }

        p_apilar(auxOriginal, elem);
    }

    while (!p_es_vacia(auxOriginal)) {
        p_apilar(p, p_desapilar(auxOriginal));
    }

    return resultado; 
} // O(n^2)
