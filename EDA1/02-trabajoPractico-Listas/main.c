#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tp_2_listas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

#define salto printf("\n")

void limpiar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {

    int option, seguir;

    do {

        printf("+--------+ MENU +--------+\n");
        printf("    1 - Ejercicio 2\n");
        printf("    2 - Ejercicio 3\n");
        printf("    3 - Ejercicio 4\n");
        printf("    4 - Ejercicio 5\n");
        printf("    5 - Ejercicio 6\n");
        printf("    0 - Salir\n");
        printf("+------------------------+\n");

        printf("Seleccione una opcion (0 - 5): ");
        scanf("%d", &option);

        while (getchar() != '\n');

        switch(option) {

            case 0:
                // salir
                break;

            case 1:

                seguir = 1;

                while (seguir) {

                    int number = 0;
                    Lista l1 = l_crear(), l2 = l_crear();

                    limpiar();
                    printf("+-----+ EJERCICIO 2 +-----+\n");

                    srand(time(NULL));
                    
                    // insertar valores aleatorios
                    for (int i = 0; i < 10; i++) {

                        l_agregar(l1, te_crear(rand() % 10));
                        l_agregar(l2, te_crear(rand() % 10));
                    }

                    salto;

                    printf("Lista 1 "); l_mostrar(l1);
                    printf("Lista 2 "); l_mostrar(l2);
                    salto;

                    // punto A.
                    Lista noRepetidos_a_2 = verElementosQueNoSeRepiten(l1, l2);
                    printf("A: mostrar valores que estan en la l1 pero no en la l2\n");
                    l_mostrar(noRepetidos_a_2);
                    salto;

                    // punto B.
                    Lista noRepetidos_b_2 = verElementosQueNoSeRepiten(l2, l1);
                    printf("B: mostrar valores que estan en la l2 pero no en la l1\n");
                    l_mostrar(noRepetidos_b_2);
                    salto;
                    
                    // punto C.
                    Lista repetidos_2 = verElementosRepetidos(l1, l2);
                    printf("C: mostrar valores que estan en ambas listas\n");
                    l_mostrar(repetidos_2);
                    salto;
                    
                    // punto D.
                    Resultados resultados_2 = promedioAmbasListas(l1, l2);
                    printf("D: mostrar promedio de ambas listas\n");
                    printf("Promedio lista 1: %.2f\nPromedio lista 2: %.2f", resultados_2.resultado1, resultados_2.resultado2);
                    salto;
                    salto;
                    
                    // punto E.
                    ResultadoValorMaximo resultadoMinimo_2 = valorMaximo(l1, l2);
                    printf("E: mostrar el valor minimo y su posicion ordinal\n");
                    printf("Valor minimo: %d - Pos. ordinal: %d - lista: %d\n", resultadoMinimo_2.valor, resultadoMinimo_2.pos, resultadoMinimo_2.lista);
                    
                    printf("\nDesea repetir el ejercicio? (1 = Si / 0 = No): ");
                    scanf("%d", &seguir);
                }

                limpiar();
                break;


            case 2:
                
                seguir = 1;

                while (seguir) {

                    int number = 0;
                    Lista l1 = l_crear(), l2 = l_crear();

                    limpiar();
                    printf("+-----+ EJERCICIO 3 +-----+\n");
                    printf("Dadas 2 listas (L1 y L2) determinar si L2 es multiplo de L1. Se considera multiplo si cada"
                            " elemento de L2 se divide en forma exacta por el valor L1 de la misma posicion\n");
                    
                    salto;
                    printf("Lista 1:\n");
                    while (number != -1 && !l_es_llena(l1)) {
                        printf("Ingrese un numero entero (-1 para continuar): ");
                        if (scanf("%d", &number) != 1) {
                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }
                        if (number < 1 && number != -1) {
                            printf("El numero tiene que ser mayor a 0.\n\n");
                            continue;
                        }
                        if (number == -1 && l_es_vacia(l1)) {
                            printf("La lista 1 esta vacia, no se puede continuar.\n\n");
                            continue;
                        }

                        if (number != -1) {
                            l_agregar(l1, te_crear(number));
                            printf("Se agrego correctamente...\n\n");
                        }
                        

                    };

                    printf("\nLista 2:\n");
                    while (l_longitud(l2) < l_longitud(l1)) {

                        printf("Ingrese un numero entero (%d/%d): ", l_longitud(l2)+1, l_longitud(l1));

                        if (scanf("%d", &number) != 1) {
                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }
                        if (number < 1) {
                            printf("El numero tiene que ser mayor a 0.\n\n");
                            continue;
                        }

                        l_agregar(l2, te_crear(number));
                        printf("Se agrego correctamente...\n\n");

                    };
                    
                    ResultadosMul resultado_3 = multiplo(l1, l2);

                    if (resultado_3.esMultiplo) {
                        printf("L2 es multiplo de L1");

                        if (resultado_3.escalar) printf(" y ademas L2 es multiplo de L1 por un escalar, el escalar es %d.\n", resultado_3.numEscalar);
                        else printf(".\n");
                    }
                    else printf("L2 no es multiplo de L1.\n");

                    printf("\nDesea repetir el ejercicio? (1 = Si / 0 = No): ");
                    scanf("%d", &seguir);
                }
                
                limpiar();
                break;

            case 3:
                
                seguir = 1;

                while(seguir) {

                    int number = 0;
                    Lista l1 = l_crear(), l2 = l_crear();

                    limpiar();
                    printf("+-----+ EJERCICIO 4 +-----+\n");
                    printf("Dadas dos listas L1 y L2, se pide compararlas siempre en el sentido L1 > L2. Por lo tanto "
                        "puede suceder que: L1 > L2, L1 = L2 o L1 < L2. La forma de obtener la comparacion es por "
                        "la clave, posicion a posicion, donde si L1 tiene mas cantidad de claves mayores que L2 se "
                        "considera L1 > L2, por el contrario se considera L1 < L2, o de lo contrario L1 sera igual a L2. "
                        "Determinar la complejidad algoritmica de la solucion empleada.\n");

                    salto;
                    printf("Lista 1:\n");
                    while (number != -1 && !l_es_llena(l1)) {

                        printf("Ingrese un numero entero (-1 para continuar): ");

                        if (scanf("%d", &number) != 1) {
                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }
                        if (number == -1 && l_es_vacia(l1)) {
                            printf("La lista 1 esta vacia, no se puede continuar.\n\n");
                            continue;
                        }

                        if (number != -1) {
                            l_agregar(l1, te_crear(number));
                            printf("Se agrego correctamente...\n\n");
                        }  

                    };

                    printf("\nLista 2:\n");
                    while (l_longitud(l2) < l_longitud(l1)) {

                        printf("Ingrese un numero entero (%d/%d): ", l_longitud(l2)+1, l_longitud(l1));

                        if (scanf("%d", &number) != 1) {
                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        l_agregar(l2, te_crear(number));
                        printf("Se agrego correctamente...\n\n");

                    };

                    CompararListas(l1, l2);

                    printf("\nDesea repetir el ejercicio? (1 = Si / 0 = No): ");
                    scanf("%d", &seguir);
                }
                
                limpiar();
                break;

            case 4:

                seguir = 1;

                while (seguir) {

                    limpiar();
                    printf("+-----+ EJERCICIO 5 +-----+\n");
                    printf("Generar un algoritmo que guarde en una lista enlazada los coeficientes de un polinomio. "
                        "Realizar una funcion que, dada la lista de coeficientes y un cierto valor de X, nos devuelva "
                        "el valor del polinomio para ese punto. "
                        "Luego realizar un proceso que, dado un rango de valores de X y un valor de intervalo I, "
                        "retorne una lista con los valores de Y o F(x).\n");

                    salto;
                    double x, y, sumando;
                    while (1) {
                        printf("Ingrese un valor numerico para X: ");

                        if (scanf("%lf", &x) != 1) {
                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        break;
                    }

                    while (1) {
                        printf("Ingrese un valor numerico para Y: ");

                        if (scanf("%lf", &y) != 1) {
                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        break;
                    };

                    while(1) {
                        printf("Ingrese el intervalo (puede ser positivo o negativo segun el rango): ");

                        if (scanf("%lf", &sumando) != 1) {
                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        if (sumando == 0) {
                            printf("El intervalo no puede ser 0.\n\n");
                            continue;
                        }

                        if (x < y && sumando < 0) {
                            printf("El valor del intervalo tiene que ser mayor a 0.\n\n");
                            continue;
                        }

                        if (x > y && sumando > 0) {
                            printf("El valor del intervalo tiene que ser menor a 0.\n\n");
                            continue;
                        }

                        break;
                    };
                    salto;

                    Lista list = l_crear();
                    hacerPolinomio(list);
                    Lista list_calculado = calcularRango(list, x, y, sumando);
                    salto;

                    Iterador list_calculado_ite = iterador(list_calculado);
                    
                    for (double i = x; (sumando > 0) ? i <= y : i >= y; i += sumando) {
                        
                        if (i == (int)i) printf("F(%d) = %d\n", (int)i, siguiente(list_calculado_ite)->clave);
                        else printf("F(%.1f) = %d\n", i, siguiente(list_calculado_ite)->clave);

                    }

                    printf("\nDesea repetir el ejercicio? (1 = Si / 0 = No): ");
                    scanf("%d", &seguir);
                }

                limpiar();
                break;

            case 5:

                seguir = 1;

                while (seguir) {

                    int number = 0;
                    Lista l1 = l_crear(), l2 = l_crear();

                    limpiar();
                    printf("+-----+ EJERCICIO 6 +-----+\n");
                    printf("Generar un algoritmo que determine si una lista es sublista de otra. "
                        "Se considera que es una sublista si todos los valores de la segunda se encuentran dentro de la primera sin "
                        "importar el orden o posicion de cada elemento. La comparacion es solo por la clave. "
                        "Se pide ademas determinar la complejidad algoritmica de la solucion.\n");

                    salto;
                    printf("Lista 1:\n");
                    while (number != -1 && !l_es_llena(l1)) {

                        printf("Ingrese un numero entero (-1 para continuar): ");

                        if (scanf("%d", &number) != 1) {
                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }
                        if (number == -1 && l_es_vacia(l1)) {
                            printf("La lista 1 esta vacia, no se puede continuar.\n\n");
                            continue;
                        }

                        if (number != -1) {
                            l_agregar(l1, te_crear(number));
                            printf("Se agrego correctamente...\n\n");
                        }  

                    };

                    number = 0;

                    printf("\nLista 2:\n");
                    while (l_longitud(l2) < l_longitud(l1) && number != -1) {

                        printf("Ingrese un numero entero (-1 para continuar): ");

                        if (scanf("%d", &number) != 1) {
                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        if (number == -1 && l_es_vacia(l2)) {
                            printf("La lista 1 esta vacia, no se puede continuar.\n\n");
                            continue;
                        }

                        if (number != -1) {
                            l_agregar(l2, te_crear(number));
                            printf("Se agrego correctamente...\n\n");
                        }  

                    };

                    salto;
                    if (esSublista(l1, l2)) printf("L2 SI es sublista de L1.\n");
                    else printf("L2 NO es sublista de L1.\n");

                    printf("\nDesea repetir el ejercicio? (1 = Si / 0 = No): ");
                    scanf("%d", &seguir);
                }
                
                limpiar();
                break;

            default:
                limpiar();
                printf("Opcion Invalida.\n\n");

        }
    } while (option != 0);


}
