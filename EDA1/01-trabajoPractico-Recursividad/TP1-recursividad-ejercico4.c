#include <stdio.h>
#include <stdlib.h>

/* Dados los números enteros m y n, construir una función recursiva que devuelva el
cociente de ambos, calculando el mismo mediante restas sucesivas. Se deberá tener
en cuenta que en el caso de que la división no sea exacta, se devolverán hasta “n”
cifras decimales (si es necesario), donde “n” es un valor entre 1 a 10 a ingresar como
precisión de la división.
Ejemplos:
division (10,2) => 5 (en este caso “n” podría haber sido cualquier valor, nada cambia el
resultado porque la división fue exacta.)
division (22,3) => 7,33333 (en este caso “n” fue 5)
division (23,4) => 5,75 (en este caso “n” fue 3, pero como el resultado con 2 decimales
fue suficiente no es necesario mostrar el 5,750 (es decir el “0” final no se muestra)*/
int cocienteEntero(int dividendo, int divisor) {
    if (dividendo < divisor)
        return 0;
    return 1 + cocienteEntero(dividendo - divisor, divisor);
}


void divisionRec(int m, int n, int precision, int decimalesYa, int esPrimeraLlamada) {

    int cociente = cocienteEntero(m, n);   
    int resto    = m - cociente * n;        

    if (esPrimeraLlamada) {
        // Imprimir la parte entera
        printf("%d", cociente);

        if (resto == 0 || precision == 0) {
          
            return;
        }
        
        printf(",");
        divisionRec(resto * 10, n, precision, 1, 0);

    } else {
        
        if (decimalesYa > precision || resto == 0) {
            
            return;
        }

        printf("%d", cociente);

        if (resto == 0) return;

        divisionRec(resto * 10, n, precision, decimalesYa + 1, 0);
    }
}


void division(int m, int n, int precision) {
    if (n == 0) {
        printf("Error: division por cero.\n");
        return;
    }

    // Manejar signos
    int signo = 1;
    if ((m < 0) != (n < 0)) signo = -1;
    if (m < 0) m = -m;
    if (n < 0) n = -n;

    if (signo == -1) printf("-");

    divisionRec(m, n, precision, 0, 1);
    printf("\n");
}


int main(void) {
    int m, n, prec;
    char opcion;

    printf("==========================================\n");
    printf("  Division Recursiva por Restas Sucesivas \n");
    printf("==========================================\n\n");

    do {
        printf("Ingrese el dividendo (m): ");
        scanf("%d", &m);

        printf("Ingrese el divisor  (n): ");
        scanf("%d", &n);

        if (n == 0) {
            printf("  [ERROR] El divisor no puede ser cero.\n\n");
            printf("Desea intentar de nuevo? (s/n): ");
            scanf(" %c", &opcion);
            printf("\n");
            continue;
        }

        printf("Precision decimal (1-10): ");
        scanf("%d", &prec);
        if (prec < 1)  prec = 1;
        if (prec > 10) prec = 10;

        printf("\n  division(%d, %d) con precision %d => ", m, n, prec);
        division(m, n, prec);
        printf("\n");

        printf("Desea probar otra division? (s/n): ");
        scanf(" %c", &opcion);
        printf("\n");

    } while (opcion == 's' || opcion == 'S');

    printf("Programa finalizado. Hasta luego!\n");
    return 0;
}