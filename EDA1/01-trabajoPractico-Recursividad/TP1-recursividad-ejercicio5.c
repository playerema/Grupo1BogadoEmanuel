#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Generar un algoritmo recursivo que le ponga los “.” de los 
miles a un String de números. 
Ejemplos: agregarSeparadorMiles (“123456”) => “123.456” 
agregarSeparadorMiles (“12345678”) => “12.345.678”, 
que tenga una parte donde el usuario pueda verificar 
por teclado si todo esta bien*/
int agregarSeparadorRec(const char *src, int si, int len, char *dest, int di) {
    if (len == 0) {
        dest[di] = '\0';
        return di;
    }

   
    dest[di] = src[si];
    di++;

    len--;

    
    if (len > 0 && len % 3 == 0) {
        dest[di] = '.';
        di++;
    }

    return agregarSeparadorRec(src, si + 1, len, dest, di);
}


void agregarSeparadorMiles(const char *numero, char *resultado) {
    int len = strlen(numero);

    if (len == 0) {
        resultado[0] = '\0';
        return;
    }

    agregarSeparadorRec(numero, 0, len, resultado, 0);
}


int main(void) {
    char entrada[200];
    char salida[300];
    char opcion;

    printf("=========================================\n");
    printf("  Separador de Miles - Algoritmo Recursivo\n");
    printf("=========================================\n\n");

    do {
        printf("Ingrese un numero (solo digitos): ");
        scanf("%199s", entrada);

        
        int valido = 1;
        for (int i = 0; entrada[i] != '\0'; i++) {
            if (entrada[i] < '0' || entrada[i] > '9') {
                valido = 0;
                break;
            }
        }

        if (!valido) {
            printf("  [ERROR] Solo se permiten digitos numericos. Intente de nuevo.\n\n");
            continue;
        }

        agregarSeparadorMiles(entrada, salida);

        printf("\n  Entrada : %s\n", entrada);
        printf("  Salida  : %s\n\n", salida);

        printf("Desea probar otro numero? (s/n): ");
        scanf(" %c", &opcion);
        printf("\n");

    } while (opcion == 's' || opcion == 'S');

    printf("Programa finalizado. Hasta luego!\n");
    return 0;
}