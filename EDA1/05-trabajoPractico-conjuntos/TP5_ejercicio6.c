#include <stdio.h>
#include <stdbool.h>
#include "./conjuntos.h"
#include "./conjuntos_listas.c"
#include "./tipo_elemento.h"
#include "./tipo_elemento.c"

bool c_ej6_subconjuntopropio(Conjunto A, Conjunto B){
    int cantA = cto_cantidad_elementos(A);
    if(cantA >= cto_cantidad_elementos(B)){
        return false;
    }

    if(cto_cantidad_elementos(cto_interseccion(A,B)) == cantA){
        return true;
    }

    return false;
}


int main(){
    Conjunto A=cto_crear();
    cto_agregar(A,te_crear(3));
    cto_agregar(A,te_crear(4));
    cto_agregar(A,te_crear(17));

    Conjunto B=cto_crear();
    cto_agregar(B,te_crear(1));
    cto_agregar(B,te_crear(2));
    cto_agregar(B,te_crear(3));  
    cto_agregar(B,te_crear(4));  
    cto_agregar(B,te_crear(5));  
    cto_agregar(B,te_crear(6));  
    cto_agregar(B,te_crear(7));  
    cto_agregar(B,te_crear(8));
    cto_agregar(B,te_crear(9)); 

    if(c_ej6_subconjuntopropio(A,B)){
        printf("cierto");
    }else{
        printf("falso");
    }

    return 0;
}