#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tp_1_recursividad.h"
/*10. Se dice que N es un número explosivo cuando éste explota en varios fragmentos más
chicos que él, dada una bomba B. Si se tiene que N es el número y B la bomba, tales
que N es mayor que B, se puede hacer que N explote en dos números N1 = N / B
(división entera) y N2 = N - (N / B).
Pero B es una bomba que produce una reacción en cadena, si N1 o N2 son mayores que
B, estos también explotan con la regla anterior, hasta que se encuentre que el número
no es mayor que B; entonces se dice que ya no se puede explotar el número.
Escribe una función recursiva que retorne una lista con los pedazos del número N,
dado que se tiene la bomba B.*/

/*Ejemplos:
Número: 10
Bomba: 3
explosion(10, 3) => [3 2 1 1 3]
Número: 20
Bomba: 5
explosion(20, 5) => [4 3 2 2 1 1 1 1 5]*/

/*int* explosion(int n,int b){
    if(n<=b){
        printf("%d",n);
    }else{
        explosionAux((n - n%b)/b,b);
        explosionAux(n - ((n - n%b)/b),b);
    }
}*/

int* explotar(int N, int B, int* cantidad) {
    if (B <= 1) {//sí b es menor a 1 retorna null por no poder hacer el calculo
        *cantidad = 0;
        return NULL;
    }

    if (N <= B) {//sí n es menor a b
        int* resultado = malloc(sizeof(int));//reserva el espacio en memoria para guardar N 
        resultado[0] = N;//guarda N
        *cantidad = 1;
        return resultado;//retorna el resultado
    }

    int cant1, cant2;
    int* parte1 = explotar(N/B, B, &cant1);
    int* parte2 = explotar(N-(N/B), B, &cant2);

    int* resultado = malloc((cant1 + cant2) * sizeof(int));

    for (int i = 0; i < cant1; i++) {
        resultado[i] = parte1[i];
    }
    for (int i = 0; i < cant2; i++) {
        resultado[cant1 + i] = parte2[i];
    }

    *cantidad = cant1 + cant2;
    free(parte1);
    free(parte2);

    return resultado;
}

int cant;

int* explosion(int N,int B){
    
    return explotar(N,B,&cant);
}


int main(){
    int* lista = explosion(10,3);

    printf("n = 10 b = 3:\n");
    for(int i=0;i<cant;i++){
        printf("%d\n",lista[i]);
    }

    int* lista2 = explosion(20,5);
    
    printf("n = 20,b = 5:\n");
    for(int i=0;i<cant;i++){
        printf("%d\n",lista2[i]);
    }
    free(lista);
    free(lista2);
    return 0;
}