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
    if(n!=1){
        char *ant = reunionMafia(n-1);
        int tam = strlen(ant)+7;
        c=malloc(tam);
        c[0]='\0';

        strcat(c,"(-.");
        strcat(c,ant);
        strcat(c,".-)");
        free(ant);
    }else{
        c = malloc(6);
        strcpy(c,"(-.-)");
    }
    return c;
}

int main(){
    char *f1 = reunionMafia(1);
    printf(f1);
    printf("\n");
    char *f2 = reunionMafia(2);
    printf(f2);
    printf("\n");
    char *f3 = reunionMafia(3);
    printf(f3);
    printf("\n");
    char *f4 = reunionMafia(4);
    printf(f4);
    return 0;
    }