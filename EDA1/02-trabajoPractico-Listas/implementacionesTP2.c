#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "tp_2_listas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

//P2
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
            if (elemento_l1->clave == elemento_l2->clave && l_buscar(repetidos, elemento_l1->clave) == NULL) {
                
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

        if (!coincidencia && l_buscar(noRepetidos, elemento_l1->clave) == NULL) l_agregar(noRepetidos, elemento_l1);
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

    ResultadoValorMinimo resultados;

    resultados.pos = pos_l1;
    resultados.valor = minimo_l1->clave;
    resultados.pos_2 = pos_l2;
    resultados.valor_2 = minimo_l2->clave;

    return resultados;
}

//P3
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

//P4
// Complejidad: O(n)
int CompararListas(Lista L1, Lista L2)
{
    int contador = 0;
    int resu;
    Iterador Iterador1 = iterador(L1);
    Iterador Iterador2 = iterador(L2);
    
    while(hay_siguiente(Iterador1) && hay_siguiente(Iterador2))
    {
        TipoElemento elemento1 = siguiente(Iterador1); 
        TipoElemento elemento2 = siguiente(Iterador2);
        if(elemento1->clave > elemento2->clave)
        {
            contador++;
        }
        else if(elemento1->clave < elemento2->clave)
        {
            contador--;
        }
    }
    if(contador > 0)
    {
        resu = 1;
    }
    else if(contador < 0)
    {
        resu = 2;
    }
    else if(contador == 0)
    {
        resu = 0;
    }
    else
    {
        resu = -1;
    }

    return resu;
}

// P5
void hacerPolinomio(Lista list) {

    int grado;

    printf("Ingrese el grado del polinomio: ");
    scanf("%d", &grado);

    for (int i = grado; i >= 0; i--) {

        float* coef = malloc(sizeof(float));

        printf("Coeficiente de x^%d: ", i);
        scanf("%f", coef);

        l_agregar(list, te_crear_con_valor(i, coef));
    }
}

float evaluarPoliomio(Lista list, float x) {

    float resultado = 0;

    Iterador ite = iterador(list);

    while (hay_siguiente(ite)) {

        TipoElemento elemento = siguiente(ite);

        float coef = *(float*) elemento->valor;
        int grado = elemento->clave;

        resultado += coef * pow(x, grado);
    }

    return resultado;
}

Lista calcularRango(Lista list, double x, double y, double sumando) {

    Lista resultado = l_crear();

    for (double i = x; (sumando > 0) ? i <= y : i >= y; i += sumando) {

        float valor = evaluarPoliomio(list, i);

        float* res = malloc(sizeof(float));
        *res = valor;

        l_agregar(resultado, te_crear_con_valor(0, res));
    }

    return resultado;
}

//P6
// Complejidad: O(n²)
bool esSublista(Lista l1, Lista l2) {

    Iterador l2_ite = iterador(l2);
    bool esta = true;

    while (hay_siguiente(l2_ite) && esta) {

        Iterador l1_ite = iterador(l1);
        TipoElemento elem_l2 = siguiente(l2_ite);
        bool corte = false;

        while (hay_siguiente(l1_ite) && !corte) {

            TipoElemento elem_l1 = siguiente(l1_ite);

            if (elem_l1->clave == elem_l2->clave) {
                corte = true;
            }
        }

        if (!corte) esta = false;

    }

    return esta;
}
