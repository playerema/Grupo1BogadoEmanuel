#include <stdio.h>
#include <stdbool.h>
#include "tp_1_recursividad.h"
//#include <D:\universidad\estructura de datos y algoritmos 1\TP1 - recursividad\tp1 recursividad\tp_1_recursividad.h>

/*9. Escribir una función recursiva que implemente el método que se describe para saber si
un número es divisible por 7. Se separa la primera cifra de la derecha, se la multiplica
por 2, y se resta este producto de lo que queda a la izquierda y así sucesivamente,
hasta que el resultado obtenido sea un número menor a 70. El número original será
múltiplo de 7 si el resultado da cero o múltiplo de 7.*/

bool divisiblePor7(int n){
    if(n<=70){ return n%7==0;}
    
    int derecha = n%10;
    int izquierda = (n-derecha)/10;
    
    return divisiblePor7(izquierda-derecha*2);
}
void main(){
    printf("32291 es multiplo de 7: %d\n",divisiblePor7(32291));
    printf("110 es multiplo de 7: %d",divisiblePor7(110));
}