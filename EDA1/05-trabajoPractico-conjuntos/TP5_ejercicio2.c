#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tipo_elemento.h"
#include "listas.h"
#include "conjuntos.h"
#define N 6

void llenar(Conjunto c);
void opcion(Conjunto c1, Conjunto c2);
void menu(Conjunto c1, Conjunto c2);

void llenar(Conjunto c){
    for(int i = 0; i < N; i++){
        int num = rand() %9 +1;
        cto_agregar(c, te_crear(num));
    }
}

void opcion(Conjunto c1, Conjunto c2){
    int op;
    printf("\nDesea continuar: \nNo -> 0 \nSi -> 1\nIngrese su opcion -> ");
    scanf("%d", &op);

    while(op != 0 && op != 1){
        printf("Opcion incompaltible. Intente nuevamente");
        printf("\nDesea continuar: \nNo -> 0 \nSi -> 1\nIngrese su opcion -> ");
        scanf("%d", &op);
        }
            
    if(op == 1)
        menu(c1, c2);
    
    else{
        if(op == 0){
            printf("Saliendo...");
            return;
        }
    }
}

//Unión,  Intersección,  Diferencia y Pertenencia

void menu(Conjunto c1, Conjunto c2){
    int eleccion, elemento, conjun;
    bool respuesta;
    Conjunto resultado = cto_crear();
    printf("\n=============================================\n");
    printf("               MENU DE PRUEBAS                \n");
    printf("=============================================\n");
    printf("Conjunto 1:\n");
    cto_mostrar(c1);
    printf("Conjunto 2:\n");
    cto_mostrar(c2);
    printf("---------------------------------------------\n");
    printf("1. Unir los conjunto C1 y C2\n");
    printf("2. Intersectar los elementos en comun de C1 y C2\n");
    printf("3. Mostrar la diferencia entre C1 y C2\n");
    printf("4. Verificar la pertenencia de un elemento en uno de los conjuntos\n");
    printf("5. Recargar un conjunto con nuevos valores al azar\n");
    printf("0. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &eleccion);

    switch(eleccion){
        case 1:
            resultado = cto_union(c1, c2);
            printf("\nSe han unido los contenidos de los conjuntos exitosamente \nEl conjunto resultante es el siguiente\n");
            cto_mostrar(resultado);
            break;

        case 2:
            resultado = cto_interseccion(c1, c2);
            printf("\nLos elementos en comun en ambos conjuntos son los siguiente\n");
            cto_mostrar(resultado);
            break;
        
        case 3:
            resultado = cto_diferencia(c1, c2);
            printf("\nLos elementos que hacen diferentes a ambos conjuntos son...\n");
            cto_mostrar(resultado);
            break;
        
        case 4:
            printf("\nIngrese el elemento que desea buscar en uno de los conjuntos: ");
            scanf("%d", &elemento);
            printf("\nA que conjunto elige para que sea verificado? \nIngrese el 1 para el conjunto 1 \nIngrese el 2 para el conjunto 2\n");
            scanf("%d", &conjun);

            while(conjun != 1 && conjun != 2){
                printf("Opción invalida \nIntente nuevamente");
                printf("\nA que conjunto elige para que sea verificado? \nIngrese el 1 para el conjunto 1 \nIngrese el 2 para el conjunto 2\n");
                scanf("%d", &conjun);
            }
            
            if(conjun == 1)
                respuesta = cto_pertenece(c1, elemento);
            else{
                respuesta = cto_pertenece(c2, elemento);
            }

            if(respuesta == true)
                printf("El elemento PERTENECE al conjunto\n");
            else{
                printf("El elementos NO PERTENECE al conjunto\n");
            }

            break;
        
        case 5:
            printf("\nA que conjunto desea que se le recarguen nuevos valores? \nIngrese el 1 para el conjunto 1 \nIngrese el 2 para el conjunto 2\n");
            scanf("%d", &conjun);

            while(conjun != 1 && conjun != 2){
                printf("Opción invalida \nIntente nuevamente");
                printf("\nA que conjunto desea que se le recarguen nuevos valores? \nIngrese el 1 para el conjunto 1 \nIngrese el 2 para el conjunto 2\n");
                scanf("%d", &conjun);
            }

            if(conjun == 1){
                llenar(c1);
                printf("El conjunto 1 ahora tiene los siguiente elementos\n");
                cto_mostrar(c1);
            }
            else{
                llenar(c2);
                printf("El conjunto 2 ahora tiene los siguiente elementos\n");
                cto_mostrar(c2);
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
        opcion(c1, c2); 
}

int main(){

    srand(time(NULL));

    Conjunto c1 = cto_crear();
    llenar(c1);

    Conjunto c2 = cto_crear();
    llenar(c2);

    menu(c1, c2);

    return 0;
}
