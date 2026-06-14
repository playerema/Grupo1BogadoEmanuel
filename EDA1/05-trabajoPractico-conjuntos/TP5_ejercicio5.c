#include <stdio.h>
#include <stdbool.h>
#include "./conjuntos.h"
#include "./conjuntos_listas.c"
#include "./listas.h"
#include "./listas_arreglos.c"
#include "./tp_conjunto.h"

/*5. Desarrollar un algoritmo capaz de resolver la diferencia simétrica (por la clave) entre
dos conjuntos. La diferencia simétrica es una operación entre dos conjuntos donde el
conjunto resultante está conformado por los elementos no comunes a los dos
conjuntos.*/

Conjunto c_ej5_dif_simetrica(Conjunto c1,Conjunto c2){
    return cto_union(cto_diferencia(c1,c2),cto_diferencia(c2,c1));
}

int main(){
    Conjunto a=cto_crear();
    Conjunto b=cto_crear();
    
    cto_agregar(a,te_crear(1));
    cto_agregar(a,te_crear(2));
    cto_agregar(a,te_crear(3));

    cto_agregar(b,te_crear(2));
    cto_agregar(b,te_crear(3));
    cto_agregar(b,te_crear(4));

    Conjunto c=c_ej5_dif_simetrica(a,b); 

    cto_mostrar(c);

    return 0;
}