#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tp_2_listas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

Lista verElementosRepetidos(Lista l1, Lista l2) {
    
    Lista repetidos = l_crear();

    Iterador l1_ite = iterador(l1);

    int i = 1;
    while (hay_siguiente(l1_ite)) {

        int j = 1;
        TipoElemento elemento_l1 = siguiente(l1_ite);
        Iterador l2_ite = iterador(l2);

        while (hay_siguiente(l2_ite)) {

            TipoElemento elemento_l2 = siguiente(l2_ite);
            if (elemento_l1->clave == elemento_l2->clave) {
                l_agregar(repetidos, elemento_l1);
                break;
            }
            j++;
        }
        i++;
        
    }

    return repetidos;
}

Lista verElementosQueNoSeRepiten(Lista l1, Lista l2){
    Lista noRepetidos = l_crear();

    Iterador l1_ite = iterador(l1);

    int i = 1;
    while (hay_siguiente(l1_ite)) {

        int j = 1;
        bool coincidencia = false;
        TipoElemento elemento_l1 = siguiente(l1_ite);
        Iterador l2_ite = iterador(l2);

        while (hay_siguiente(l2_ite)) {

            TipoElemento elemento_l2 = siguiente(l2_ite);
            if (elemento_l1->clave == elemento_l2->clave) {
                coincidencia = true;
                break;
            }
            j++;
        }

        if (!coincidencia) l_agregar(noRepetidos, elemento_l1);
        i++;
        
    }

    return noRepetidos;
}
float promedio(Lista l1){

    Iterador l1_ite = iterador(l1);
    int suma = 0;

    while (hay_siguiente(l1_ite)) {
        suma += siguiente(l1_ite)->clave;
    }

    return (float)suma / l_longitud(l1);
}

Resultados promedioAmbasListas(Lista l1, Lista l2){
    Resultados promedioAmbas;

    promedioAmbas.resultado1 = promedio(l1);
    promedioAmbas.resultado2 = promedio(l2);

    return promedioAmbas;
}

ResultadoValorMinimo valorMinimo(Lista l1, Lista l2){
    
    // obtener minimo y posicion ordinal de la lista 1
    Iterador l1_ite = iterador(l1);
    TipoElemento minimo_l1 = l_recuperar(l1, 1), minimo_aux_l1;

    int pos_l1 = 1, pos_aux_l1 = 1;
    
    while (hay_siguiente(l1_ite)) {
        minimo_aux_l1 = siguiente(l1_ite);
        
        if (minimo_aux_l1->clave < minimo_l1->clave) {
            minimo_l1 = minimo_aux_l1;
            pos_l1 = pos_aux_l1;
        }
        pos_aux_l1++;
    }

    // obtener minimo y posicion ordinal de la lista 2
    Iterador l2_ite = iterador(l2);
    TipoElemento minimo_l2 = l_recuperar(l2, 1), minimo_aux_l2; 
    int pos_l2 = 1, pos_aux_l2 = 1;

    while(hay_siguiente(l2_ite)) {
        minimo_aux_l2 = siguiente(l2_ite);

        if (minimo_aux_l2->clave < minimo_l2->clave) {
            minimo_l2 = minimo_aux_l2;
            pos_l2 = pos_aux_l2;
        }
        pos_aux_l2++;
        
    }

    // comparar y asignar
    ResultadoValorMinimo resultados;

    resultados.lista = (minimo_l1->clave < minimo_l2->clave) ? 1 : 2;
    resultados.valor = (minimo_l1->clave < minimo_l2->clave) ? minimo_l1->clave : minimo_l2->clave;
    resultados.pos = (minimo_l1->clave < minimo_l2->clave) ? pos_l1 : pos_l2;

    return resultados;
}
