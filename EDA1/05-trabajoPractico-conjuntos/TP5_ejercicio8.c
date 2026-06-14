#include <stdio.h>
#include <stdbool.h>
#include "./conjuntos.h"
#include "./conjuntos_listas.c"

/*8. Dados dos conjuntos de números naturales se pide determinar si son iguales sin
importar la posición de sus elementos. Determinar la complejidad algorítmica.
Ejemplo: si A = (3, 4, 5, 6) y B = (3, 5, 4, 6) entonces a “A” es igual “B” y viceversa. */
bool c_ej8_soniguales(Conjunto c1, Conjunto c2){
    return cto_es_vacio(cto_diferencia(c1,c2)) && cto_es_vacio(cto_diferencia(c2,c1));
}//o(n^2)

int main(){


    return 0;
}