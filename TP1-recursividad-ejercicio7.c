#include <string.h>
#include <stdio.h>
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

void reunionChina(int n){
    if(n!=1){
        printf("(-.");
        reunionChina(n-1);
        printf(".-)");
    }else{
        printf("(-.-)");
    }
}

void main(){
    reunionChina(1);
    printf("\n");
    reunionChina(2);
    printf("\n");
    reunionChina(3);
    printf("\n");
    reunionChina(4);
    }