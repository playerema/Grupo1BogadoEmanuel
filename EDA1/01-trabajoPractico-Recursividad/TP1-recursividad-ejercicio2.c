#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "tp_1_recursividad.h"

int producto(int m, int n){
    if (n==1) {
        return m;
    }else{
        return m + producto(m, n-1);
    }
}


int main() {
    int m;
    int n;

    // Valida las entradas de los enteros m y n
    printf("Introduce un numero entero m: ");
    while (!leer_entero(&m)) {
        printf("Entrada invalida. Intentalo de nuevo: ");
    }
    printf("Introduce un numero entero n: ");
    while (!leer_entero(&n)) {
        printf("Entrada invalida. Intentalo de nuevo: ");
    }

    printf("Has introducido el numero: %d\n", m);
    printf("Has introducido el numero: %d\n", n);


    producto(m,n);
    printf("El producto es %d\n", producto(m,n));
    return 0;
}

// funcion para validar numeros enteros
int leer_entero(int *resultado) {
    char buffer[100];
    char *endptr;
    long valor;

    //  Lee la entrada como cadena de texto
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0; // retorna 0 si hay error de lectura
    }

    // si hay un salto de linea lo elimina
    buffer[strcspn(buffer, "\n")] = 0;

    // intenta convertir a long
    valor = strtol(buffer, &endptr, 10);

    // validaciones extra
    if (buffer == endptr) {
        return 0; // no se ingresaron digitos
    }
    if (*endptr != '\0') {
        return 0; // si contiene caracteres no numericos
    }

    *resultado = (int)valor;
    return 1;
}