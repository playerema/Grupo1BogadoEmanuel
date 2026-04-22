#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tp_2_listas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

ResultadosMul multiplo(Lista l1, Lista l2) {

    // inicializamos las variables necesarias
    ResultadosMul multi;

    Iterador l1_ite = iterador(l1);
    Iterador l2_ite = iterador(l2);
    bool multiplos = true;
    bool bool_escalar = true;
    int escala = l_recuperar(l2, 1)->clave / l_recuperar(l1, 1)->clave;

    // bucle que verifique si cada elemento de L2 es multiplo de L1 y si ademas es por un "escalar"
    while (hay_siguiente(l1_ite) && hay_siguiente(l2_ite)) {

        int clave_l1 = siguiente(l1_ite)->clave; int clave_l2 = siguiente(l2_ite)->clave;

        // verificar que no sea multiplo, de ser asi, se corta el bucle
        if ((clave_l2 % clave_l1) != 0) {
            multiplos = false;
            bool_escalar = false;
            break;
        }

        // verificar en cada iterracion que la division de los elementos actuales no sea igual a "escala"
        if ((clave_l2 / clave_l1) != escala) {
            bool_escalar = false;
        }
        
    }

    multi.esMultiplo = multiplos; // bool
    multi.escalar = bool_escalar; // bool
    multi.numEscalar = bool_escalar ? escala : -1; // int

    return multi;
}