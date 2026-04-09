#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "tp_1_recursividad.h"


int terminoSeridFibonacci(int k){
    if (k<=1) {
        return k;
    }else{
        return terminoSeridFibonacci(k-1) + terminoSeridFibonacci(k-2);
    }
}

int main(){
    int k;
    // valida que la entrada sea un entero y mayor que cero (0)
    printf("Ingresa el numero k: ");
    while (!leer_entero(&k) || k < 0) {
        printf("Error: Ingresa un numero entero positivo: ");
    }

    printf("Termino k-esimo de Fibonacci es: %d\n", terminoSeridFibonacci(k));
    return 0;
}

// funcion para validar el numero entero
int leer_entero(int *resultado) {
    char buffer[100];
    char *endptr;
    long valor;

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0;
    }

    // elimina el salto de linea
    buffer[strcspn(buffer, "\n")] = 0;

    valor = strtol(buffer, &endptr, 10);

    // validaciones extra
    if (buffer == endptr || *endptr != '\0') {
        return 0; // el numero no es valido
    }


    *resultado = (int)valor;
    return 1;
}