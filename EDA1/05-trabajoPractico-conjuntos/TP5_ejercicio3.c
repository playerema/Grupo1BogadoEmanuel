#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "conjuntos.h" 
#include "tipo_elemento.h"
#include "listas.h"
#define N 4

void llenar(Conjunto[], int);
Conjunto uniones(Conjunto[], int);
Conjunto intersecciones(Conjunto[], int);
void opcion(Conjunto[], int);
void menu(Conjunto[], int);

void llenar(Conjunto coleccion[], int cant){
    for(int i = 0; i < cant; i++){
        Conjunto c = cto_crear();
        for(int j = 0; j < N; j++){
            int num = rand() %4 +1;
            cto_agregar(c, te_crear(num));
        }
        coleccion[i] = c;   
    }
}

Conjunto uniones(Conjunto coleccion[], int cant){
    Conjunto resultado = cto_crear();

    for(int i = 0; i < cant; i++){
        resultado = cto_union(resultado, coleccion[i]);
    }

    return resultado;
}

Conjunto intersecciones(Conjunto coleccion[], int cant){
    Conjunto resultado = coleccion[0];
    
    for(int i = 1; i < cant; i++){
        resultado = cto_interseccion(resultado, coleccion[i]);
    }

    return resultado;
}

void opcion(Conjunto coleccion[], int cant){
    int op;
    printf("\nDesea continuar: \nNo -> 0 \nSi -> 1\nIngrese su opcion -> ");
    scanf("%d", &op);

    while(op != 0 && op != 1){
        printf("Opcion incompatible. Intente nuevamente");
        printf("\nDesea continuar: \nNo -> 0 \nSi -> 1\nIngrese su opcion -> ");
        scanf("%d", &op);
        }
            
    if(op == 1)
        menu(coleccion, cant);
    
    else{
        if(op == 0){
            printf("Saliendo...");
            return;
        }
    }
}



void menu(Conjunto coleccion[], int cant){
    int eleccion;
    Conjunto res = cto_crear();
    
    printf("\n=============================================\n");
    printf("               MENU DE PRUEBAS                \n");
    printf("=============================================\n");
    for(int i = 0; i < cant; i++){
        printf("Conjunto %d:\n", i + 1);
        cto_mostrar(coleccion[i]);
    }
    printf("---------------------------------------------\n");

    printf("1. Unir los conjuntos en un unico conjunto\n");
    printf("2. Dar un conjunto con los valores en comun de la coleccion\n");
    printf("3. Recargar un conjunto con nuevos valores al azar\n");
    printf("0. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &eleccion);

    switch(eleccion){
        case 1:
            res = uniones(coleccion, cant);
            printf("\nEl resultado de la union es el siguiente:\n");
            cto_mostrar(res);
            break;

        case 2:
            res = intersecciones(coleccion, cant);
            if(cto_es_vacio(res))
                printf("\nNo hay elementos en comun\n");
            else{
                printf("\nLos elementos en comun son:\n");
                cto_mostrar(res);
            }
            
            break;

        case 3:
            llenar(coleccion, cant);
            printf("\nLa coleccion tiene nuevos valores");
            break;

        case 0:
            printf("Sesion cerrada\n");
            break;

        default:
            printf("Opcion invalida. Intente nuevamente.\n");
            break;
    }
    if(eleccion != 0)
        opcion(coleccion, cant); 
}

int main(){
    
    srand(time(NULL));

    int cant = 5;

    Conjunto coleccion[5];

    llenar(coleccion, cant);

    menu(coleccion, cant);

    return 0;
}
