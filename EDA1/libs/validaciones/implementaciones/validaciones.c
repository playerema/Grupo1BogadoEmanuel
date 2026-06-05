#include <stdio.h>
#include "../headers/validaciones.h"

int repetir_ejercicio() {

    int x;

    while (1) {
        printf("\nDesea repetir el ejercicio? (1 = Si / 0 = No): ");
        if (scanf("%d", &x) != 1) {

            printf("Dato invalido.\n\n");
            while (getchar() != '\n');
            continue;
        }

        if (x != 1 && x != 0) {

            printf("Ingrese unicamente 1 o 0.\n\n");
            while (getchar() != '\n');
            continue;
        }

        break;
    }

    return x;
    
}