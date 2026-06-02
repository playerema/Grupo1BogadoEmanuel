#include <stdio.h>
#include <stdlib.h>
#include "colas.h"
#include "tipo_elemento.h"
#include <time.h>
#include <stdbool.h>
#define N 6

bool buscar(Cola, int);
Cola insertar(Cola, int, int);
void sacar(Cola, int);
int contar(Cola);
Cola doble(Cola);
void inver(Cola);
Cola invertir(Cola);
void crear(Cola);
void opcion(Cola, int);
void menu(Cola, int);


bool buscar(Cola cola, int numero){        // Ejercicio A
    Cola cola_aux = c_crear();
    TipoElemento te;
    bool encontrado = false;

    while(!c_es_vacia(cola)){
        te = c_desencolar(cola);
        if(te->clave == numero)
            encontrado = true;
        c_encolar(cola_aux, te);
    }
    while(!c_es_vacia(cola_aux)){
        te = c_desencolar(cola_aux);
        c_encolar(cola, te);
    }
    return encontrado;
}

Cola insertar(Cola cola, int num, int pos){         // Ejercicio B
    Cola cola_aux = c_crear();
    TipoElemento te;
    int pos_actual = 1;

    while(!c_es_vacia(cola)){
        te = c_desencolar(cola);
        if(pos_actual == pos){
            c_encolar(cola_aux, te_crear(num));
        }
        c_encolar(cola_aux, te);
        pos_actual++;   
    }
    if(pos >= pos_actual){
        c_encolar(cola_aux, te_crear(num));
    }
    while(!c_es_vacia(cola_aux)){
        te = c_desencolar(cola_aux);
        c_encolar(cola, te);
    }
    return cola;
}

void sacar(Cola cola, int num){          // Ejercicio C
    Cola cola_aux = c_crear();
    TipoElemento te;

    while(!c_es_vacia(cola)){
        te = c_desencolar(cola);
        if(te->clave != num)
            c_encolar(cola_aux, te);
    }
    while(!c_es_vacia(cola_aux)){
        te = c_desencolar(cola_aux);
        c_encolar(cola, te);
    }
}

int contar(Cola cola){         // Ejercicio D
    Cola cola_aux = c_crear();
    TipoElemento te;
    int cantidad = 0;

    while(!c_es_vacia(cola)){
        te = c_desencolar(cola);
        c_encolar(cola_aux, te);
        cantidad++;
    }
    while(!c_es_vacia(cola_aux)){
        te = c_desencolar(cola_aux);
        c_encolar(cola, te);
    }
    return cantidad;
}

Cola doble(Cola cola){        // Ejercicio E
    Cola cola_aux = c_crear();
    Cola cola_doble = c_crear();
    TipoElemento te;

    while(!c_es_vacia(cola)){
        te = c_desencolar(cola);
        c_encolar(cola_aux, te);
    }
    while(!c_es_vacia(cola_aux)){
        te = c_desencolar(cola_aux);
        c_encolar(cola, te);
        c_encolar(cola_doble, te);
    }
    return cola_doble;
}

void inver(Cola cola){         // Ejercicio F
    if(c_es_vacia(cola))
        return;
    TipoElemento te = c_desencolar(cola);
    inver(cola);
    c_encolar(cola, te);
}
Cola invertir(Cola cola){
    Cola cola_final = c_crear();
    Cola cola_aux = c_crear();
    TipoElemento te;

    while(!c_es_vacia(cola)){
        te = c_desencolar(cola);
        c_encolar(cola_aux, te);
    }
    while(!c_es_vacia(cola_aux)){
        te = c_desencolar(cola_aux);
        c_encolar(cola, te);
        c_encolar(cola_final, te);
    }

    inver(cola_final);

    return cola_final;
}

void crear(Cola cola){
    while(!c_es_vacia(cola)){
        c_desencolar(cola);
    }
        
    for(int i = 0; i < N; i++){
        int num = rand() %10 +1;
        c_encolar(cola, te_crear(num));
    }
}

void opcion(Cola cola, int largo){
    int op;
    printf("\nDesea continuar: \nNo -> 0 \nSi -> 1\nIngrese su opcion -> ");
    scanf("%d", &op);

    if(op == 1){
        menu(cola, largo);
    }
    else{
        if(op == 0){
            printf("Saliendo...");
            return;
        }
        else{
            while(op != 0 && op != 1){
                if(op != 0 && op != 1){
                    printf("Opcion incompaltible. Intente nuevamente");
                    printf("\nDesea continuar: \nNo -> 0 \nSi -> 1\nIngrese su opcion -> ");
                    scanf("%d", &op);
                }
                else{
                    if(op == 1){
                        menu(cola, largo);
                    }
                    else{
                        if(op == 0){
                            printf("Saliendo...");
                            return;
                        }
                    }
                }
            }
        }
    }
}

void menu(Cola cola, int largo){
    int eleccion, elemento, pos;
    printf("\n=============================================\n");
    printf("               MENU DE PRUEBAS                \n");
    printf("=============================================\n");
    printf("Estado actual de la Cola:\n");
    c_mostrar(cola);
    printf("---------------------------------------------\n");
    printf("1. Buscar un elemento de la cola\n");
    printf("2. Insertar elemento en posicion a eleccion\n");
    printf("3. Eliminar un elemento de la cola\n");
    printf("4. Contar la cantidad de los elementos de la cola\n");
    printf("5. Realizar una copia\n");
    printf("6. Invertir el contenido de la cola\n");
    printf("7. Recargar cola con nuevos valores al azar\n");
    printf("0. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &eleccion);

    switch(eleccion){
        case 1:
            printf("Ingrese el elemento que desea buscar: \n");
            scanf("%d", &elemento);
            if(buscar(cola, elemento)){
                printf("El elemento se encuentra en la cola\n");
            }
            else{
                printf("El elemento no se encuentra en la cola\n");
            }
            break;

        case 2:
            printf("Ingrese el elemento que desea agregar a la cola\n");
            scanf("%d", &elemento);
            printf("Ingrese la posicion que desea que se encuentre su elemento entre 1 - %d\n", largo);
            scanf("%d", &pos);
            if(pos >= 1 && pos <= largo){
                cola = insertar(cola, elemento, pos);
            }
            else{
                while(pos < 1 || pos > largo){
                    if(pos < 1 || pos > largo){
                        printf("Opción incompaltible. Intente nuevamente");
                        printf("Ingrese el elemento que desea agregar a la cola\n");
                        scanf("%d", &elemento);
                        printf("Ingrese la posicion que en la que desea que se encuentre su elemento entre 1 - %d\n", largo);
                        scanf("%d", &pos);
                    }
                    else{
                        cola = insertar(cola, elemento, pos);
                    }
                }
            }
            printf("El elemento fue correctamente agregado\n");
            c_mostrar(cola);
            largo++;
            break;

        case 3:
            printf("Ingrese el elemento que desea que sea retirado de la cola\n");
            scanf("%d", &elemento);
            sacar(cola, elemento);
            printf("El elemento fue quitado\n");
            break;
        
        case 4:
            int cantidad = contar(cola);
            printf("En la cola hay %d elementos\n", cantidad);
            break;

        case 5:
            Cola copia = c_crear();
            copia = doble(cola);
            printf("La cola fue copiada\n");
            break;

        case 6:
            Cola cola_invertida = c_crear();
            cola_invertida = invertir(cola);
            printf("La cola fue invertida\n");
            c_mostrar(cola_invertida);
            break;

        case 7:
            crear(cola);
            printf("La cola fue cargada con nuevos elementos\n");
            largo = N + 1;
            break;

        case 0:
            printf("Sesion cerada\n");
            break;

        default:
            printf("Opcion invalida. Intente nuevamente.\n");
            break;
    }
    if(eleccion != 0){
        opcion(cola, largo);
    }
}

int main(){
    srand(time(NULL));
    Cola cola = c_crear();
    crear(cola);
    int largo = N + 1;
    menu(cola, largo);

    return 0;
}
