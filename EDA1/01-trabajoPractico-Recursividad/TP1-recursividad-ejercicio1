#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//Ejercicio 1
/*Construir una función recursiva que retorne verdadero si una cadena de caracteres
pasada como parámetro es un palíndromo. Ej. “neuquen” ya que se lee igual de atrás
hacia adelante.
Ejemplos:
palindromo(“neuquen”) => verdadero
palindromo(“palindromo”) => falso*/

bool palindromo(char palabra[], int n, int i){
    if(i >= n/2)
        return true;
    if(palabra[i]== palabra[n-1-i])
        return palindromo(palabra, n, i+1);
    return false;
}

int validacion(char palabra[]){
    int n = strlen(palabra); 
    if (n == 1){
        printf("ERROR\nSu ingreso no es valido, intente nuevamente");
        return 1;
    }
    return 0;
}

int main(){
    int intento = 1;
    char palabra[100];
    while(intento == 1){
        printf("\nIngrese la palabra que desea ver si es palindromo: ");
        scanf("%s", palabra);
        intento = validacion(palabra);
    }
    int n = strlen(palabra);
    if (palindromo(palabra,n,0))
        printf("%s es PALINDROMO\n", palabra);
    else    
        printf("%s no es PALINDROMO\n", palabra);
    return 0;
}
