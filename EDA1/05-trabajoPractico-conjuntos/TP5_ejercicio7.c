#include <stdio.h>
#include <stdbool.h>
#include "./conjuntos.h"
#include "./conjuntos_listas.c"
#include "./tipo_elemento.h"
#include "./tipo_elemento.c"

void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C){
    //a->b
    if( cto_cantidad_elementos(cto_interseccion(A,B)) == cto_cantidad_elementos(A) ){
        printf("A es un subconjunto total de B\n");
    }else if( cto_cantidad_elementos(cto_interseccion(A,B)) >= cto_cantidad_elementos(A)/2 ){
        printf("A es un subconjunto parcial de B\n");
    }
    //a->c
    if( cto_cantidad_elementos(cto_interseccion(A,C)) == cto_cantidad_elementos(A) ){
        printf("A es un subconjunto total de C\n");
    }else if( cto_cantidad_elementos(cto_interseccion(A,C)) >= cto_cantidad_elementos(A)/2 ){
        printf("A es un subconjunto parcial de C\n");
    }
    //b->c
    if( cto_cantidad_elementos(cto_interseccion(B,C)) == cto_cantidad_elementos(B) ){
        printf("B es un subconjunto total de C\n");
    }else if( cto_cantidad_elementos(cto_interseccion(B,C)) >= cto_cantidad_elementos(B)/2 ){
        printf("B es un subconjunto parcial de C\n");
    }
    //b->a
    if( cto_cantidad_elementos(cto_interseccion(B,A)) == cto_cantidad_elementos(B) ){
        printf("B es un subconjunto total de A\n");
    }else if( cto_cantidad_elementos(cto_interseccion(B,A)) >= cto_cantidad_elementos(B)/2 ){
        printf("B es un subconjunto parcial de A\n");
    }
    //c->a
    if( cto_cantidad_elementos(cto_interseccion(C,A)) == cto_cantidad_elementos(C) ){
        printf("C es un subconjunto total de A\n");
    }else if( cto_cantidad_elementos(cto_interseccion(C,A)) >= cto_cantidad_elementos(C)/2 ){
        printf("C es un subconjunto parcial de A\n");
    }
    //c->b
    if( cto_cantidad_elementos(cto_interseccion(C,B)) == cto_cantidad_elementos(C) ){
        printf("C es un subconjunto total de B\n");
    }else if( cto_cantidad_elementos(cto_interseccion(C,B)) >= cto_cantidad_elementos(C)/2 ){
        printf("C es un subconjunto parcial de B\n");
    }
}


int main(){
    Conjunto A=cto_crear();
    cto_agregar(A,te_crear(3));
    cto_agregar(A,te_crear(4));
    cto_agregar(A,te_crear(5));

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

    Conjunto C=cto_crear();
    cto_agregar(C,te_crear(2));
    cto_agregar(C,te_crear(4));
    cto_agregar(C,te_crear(6));
    cto_agregar(C,te_crear(8));
    cto_agregar(C,te_crear(7));

    c_ej7_subconjtotalparcial(A,B,C);

    return 0;
}