#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tp_1_recursividad.h"
/*7. Se conoce que la mafia china es muy organizada y protege mucho a sus miembros,
cuando deciden asistir a una reunión se dispone de una cantidad de chinos que
asisten, y ellos se ubican de forma que al mirarlos frontalmente generan cierto respeto
y temor. A continuación, se tiene una serie de posibles reuniones y su nivel y la
apariencia que se tiene del grupo que va a la reunión vistos frontalmente:
Nivel reunión Vista frontal de la delegación
1          (-.-)
2       (-.(-.-).-)
3    (-.(-.(-.-).-).-)
4 (-.(-.(-.(-.-).-).-).-)
Considerando esta descripción, diseñar los procesos recursivos que permitan mostrar
la apariencia del grupo de chinos que asisten a una reunión de nivel “n”.*/

char * reunionMafia(int n){
    char *c;
    if(n>1){
        char *ant = reunionMafia(n-1);
        int tam = strlen(ant)+7;
        c=malloc(tam);
        c[0]='\0';

        strcat(c,"(-.");
        strcat(c,ant);
        strcat(c,".-)");
        free(ant);
    }else if (n==1){
        c = malloc(6);
        strcpy(c,"(-.-)");
    }else{
        char * vacio=malloc(1);
        vacio[0]='\0';
        return vacio;
    }

    return c;
}

int main() {
    int nivelReunion = 1;
    bool continuar = true;
    
    while (continuar) {
        printf("Ingrese el nivel de la reunion: ");

        if (scanf("%d", &nivelReunion) != 1) {
            printf("Entrada invalida. Ingrese un numero.\n");

            // limpiar buffer
            while (getchar() != '\n');

        } else if (nivelReunion < 1) {
            printf("Nivel de reunion no valido. Ingreselo otra vez.\n");
        } else {
            continuar = false;
        }
    }
    
    char *f1 = reunionMafia(nivelReunion);
    printf("%s\n",f1);

    return 0;
}