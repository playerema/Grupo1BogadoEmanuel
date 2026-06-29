#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "tipo_elemento.h"
#include "listas.h"
#include "conjuntos.h"
#define N 4

void llenar(Conjunto);
bool transitividad(Conjunto, Conjunto);
void opcion(Conjunto, Conjunto, Conjunto);
void menu(Conjunto, Conjunto, Conjunto);

void llenar(Conjunto c){
    for(int i = 0; i < N; i++){
        int num = rand() %4 +1;
        cto_agregar(c, te_crear(num));
    }
}

bool transitividad(Conjunto con, Conjunto subcon){
    Conjunto con_aux = cto_diferencia(con, subcon);

    bool respuesta = cto_es_vacio(con_aux);

    return respuesta;
}

void opcion(Conjunto c1, Conjunto c2, Conjunto c3){
    int op;
    printf("\nDesea continuar: \nNo -> 0 \nSi -> 1\nIngrese su opcion -> ");
    scanf("%d", &op);

    while(op != 0 && op != 1){
        printf("Opcion incompaltible. Intente nuevamente");
        printf("\nDesea continuar: \nNo -> 0 \nSi -> 1\nIngrese su opcion -> ");
        scanf("%d", &op);
        }
            
    if(op == 1)
        menu(c1, c2, c3);
    
    else{
        if(op == 0){
            printf("Saliendo...");
            return;
        }
    }
}



void menu(Conjunto c1, Conjunto c2, Conjunto c3){
    int eleccion, conjun;
    
    printf("\n=============================================\n");
    printf("               MENU DE PRUEBAS                \n");
    printf("=============================================\n");
    printf("Conjunto 1:\n");
    cto_mostrar(c1);
    printf("Conjunto 2:\n");
    cto_mostrar(c2);
    printf("Conjunto 3:\n");
    cto_mostrar(c3);
    printf("---------------------------------------------\n");

    if(transitividad(c2, c3)){
        printf("C3 es subconjunto de c2 ");
        
        if(transitividad(c1, c2))
            printf("y C2 es subconjunto de C1.\nEntonces C3 también es subconjunto de C1\n");
        else{
            printf("pero C2 no es subconjunto de C1\n");
            }
    }
    else{
        printf("C3 no es subconjunto de C2 ");
        
        if(transitividad(c1, c2))
            printf("pero C2 si es subconjunto de C1.\n");
        else{
            printf("y C2 tampoco es subconjunto de C1\n");
            }
    }
    printf("---------------------------------------------\n");
    printf("1. Recargar un conjunto con nuevos valores al azar\n");
    printf("0. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &eleccion);

    switch(eleccion){
        case 1:
            printf("\nA que conjunto desea que se le recarguen nuevos valores? \nIngrese el 1 para el conjunto 1 \nIngrese el 2 para el conjunto 2\nIngrese el 3 para el conjunto 3\nIngrese el 4 para todos loc conjuntos\n");
            scanf("%d", &conjun);

            while(conjun < 1 || conjun > 4){
                printf("Opción invalida \nIntente nuevamente");
                printf("\nA que conjunto desea que se le recarguen nuevos valores? \nIngrese el 1 para el conjunto 1 \nIngrese el 2 para el conjunto 2\nIngrese el 3 para el conjunto 3\nIngrese el 4 para todos loc conjuntos\n");
                scanf("%d", &conjun);
            }

            if(conjun == 1){
                llenar(c1);
                printf("El conjunto 1 ahora tiene los siguiente elementos\n");
                cto_mostrar(c1);
            }

            if(conjun == 2){
                llenar(c2);
                printf("El conjunto 2 ahora tiene los siguiente elementos\n");
                cto_mostrar(c2);
            }

            if(conjun == 3){
                llenar(c3);
                printf("El conjunto 3 ahora tiene los siguiente elementos\n");
                cto_mostrar(c3);
            }

            if(conjun == 4){
                llenar(c1);
                llenar(c2);
                llenar(c3);
                printf("El conjunto 1 ahora tiene los siguiente elementos\n");
                cto_mostrar(c1);
                printf("El conjunto 2 ahora tiene los siguiente elementos\n");
                cto_mostrar(c2);
                printf("El conjunto 3 ahora tiene los siguiente elementos\n");
                cto_mostrar(c3);
            }
            break;

        case 0:
            printf("Sesion cerada\n");
            break;

        default:
            printf("Opcion invalida. Intente nuevamente.\n");
            break;
    }
    if(eleccion != 0)
        opcion(c1, c2, c3); 
}

int main(){
    
    srand(time(NULL));

    Conjunto c1 = cto_crear();
    llenar(c1);

    Conjunto c2 = cto_crear();
    llenar(c2);

    Conjunto c3 = cto_crear();
    llenar(c3);

    menu(c1, c2, c3);

    return 0;
}
