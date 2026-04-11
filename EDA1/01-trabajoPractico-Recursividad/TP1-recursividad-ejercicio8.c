#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tp_1_recursividad.h"

void funcionauxiliar(int conjunto[], int tamano, int indice, int n, int suma, int combinaciones[], int cant_combinaciones, char **output);
void subconjuntosQueSumanN(int conjunto[], int tamano, int n, char **output);
int validandodato(char nuemeros[], int n);
int validandorango (int n);

/* int ** subconjuntosQueSumanN(int conjunto[], int n);   <- No la use*/

int main(void){

    char *resultado= NULL;     /*variable output de la funcion subconjuntosquesuman*/
    int N=20;
    char entrada_tamano[N];
    char entrada_numeros[N];
    char entrada_sumatoria[N];     /*estos arrays son para validar entradas ya que siempre son strings*/
    

    printf("/// Subconjuntos que suman ///\nIngrese cantidad de numeros: ");
    fgets(entrada_tamano, N, stdin);

    int tamano;

    tamano= validandodato(entrada_tamano, N);
    tamano= validandorango(tamano);             /*validamos los datos*/
    int numeros[tamano];

    for(int i=0; i<tamano; i++){
        printf("Ingrese un numero: ");
        fgets(entrada_numeros, N, stdin);
        numeros[i] = validandodato(entrada_numeros, N);     /*cargamos vector para la funcionde subconjuntosquesuman*/
    }

    printf("Ingrese resultado de sumatoria: ");
    fgets(entrada_sumatoria, N, stdin);          /*validamos la tercera entrada*/
    int res_sumatoria = validandodato(entrada_sumatoria, N);


    subconjuntosQueSumanN(numeros, tamano, res_sumatoria, &resultado);     /*llamamos con entradas ya validadas y pasandole resultado*/
    if(resultado != NULL){
        printf("resultado: %s\n", resultado);   /*muestro resultado por pantalla*/
        free(resultado);         /*liberamos malloc para que no quede con basura*/
    }

    return 0;
}


void funcionauxiliar(int conjunto[], int tamano, int indice, int n, int suma, int combinaciones[], int cant_combinaciones, char **output){
    /*la variable suma es un acumulador, cant_combinaciones es el indice(contador) de el vector combinaciones[]*/
    int i;
    char numero [20]; /*el tamano=20 porque es mas del valor maximo que puede tomar un dato de tipo entero*/
    if (suma==n){
        

        if ((*output)[1] != '\0') {    /*aca usamos [1] porque [0] ya esta cargado con "["*/
            strcat(*output, ", ");
        }

        strcat(*output, "{");   /*con el strcat vamos armando el string, agregando al final del string*/

        for (i = 0; i < cant_combinaciones; i++) {
            sprintf(numero, "%d", combinaciones[i]);  /*pasamos entero a char y lo guardamos en la variable numero*/
            strcat(*output, numero);    /*vamos armando las combinaciones*/

            if (i< cant_combinaciones-1){
            strcat(*output, ", ");
            }
        }
        strcat(*output, "}");

        return;
    }
    if (indice == tamano){
        return;
    }
    

    combinaciones[cant_combinaciones]=conjunto[indice];
    funcionauxiliar(conjunto, tamano, indice+1, n, suma+conjunto[indice], combinaciones, cant_combinaciones+1, output);
    /*este llamado es para usar un valor del vector*/
    funcionauxiliar(conjunto, tamano, indice+1, n, suma, combinaciones, cant_combinaciones, output);
    /*y este llamado es para descartar un valor y usar el siguiente*/
}



void subconjuntosQueSumanN(int conjunto[], int tamano, int n, char **output){ 
    int combinaciones[1000];
    *output= malloc(1000*sizeof(char));
    if (*output==NULL){
        printf("malloc devuelve valor nulo");
        return;
    }
    strcpy(*output, "[");    /*aca usamos strcpy porque es el primer caracter, depues use strcat porque debo cargar al final*/
    funcionauxiliar(conjunto, tamano, 0, n, 0, combinaciones, 0, output ); /*los ceros son por indice=0, suma=0, cant_combinaciones=0*/
    strcat(*output, "]");
}



int validandodato(char entrada[], int n){
    char *fin;     /*esto lo declare por strtol ya que es necesario un puntero porque es uno de sus parametros*/
    bool rta= false;
    long numero= strtol(entrada, &fin, 10);
    
    while (!rta){
        if(entrada == fin){     /*aca compare el "indice" de fin, no su valor, por eso no es "*fin"*/
            printf("ERROR no se ha ingresado un numero. Ingrese un numero: \n");
            fgets(entrada,n,stdin);
            numero= strtol(entrada, &fin, 10);
        }
        else if(*fin!= '\n' && *fin != '\0'){     /*aca compare valor/ contenido */
            printf("Tipo de dato ingresado incorrecto. Ingrese un numero: \n");
            fgets(entrada,n,stdin);
            numero= strtol(entrada, &fin, 10);
        }
        else{
            rta=true;
        }
        
    }
    return (int)numero;
}



int validandorango(int n){    /*valide rango en esta funcion porque no puede ser un vector de tamano -1 ni tampoco tamano>1000, solo por poner un limite*/
    bool rta=false;

    while (!rta){
        if(n<=0 || n>=1000){
            printf("El dato ingresado esta fuera de rango. Ingrese un numero mayor a 0 y menor a 1000: ");
            char entrada [100];
            fgets(entrada, 100, stdin);
            n= validandodato(entrada, 100);
        }
        else{
            rta=true;
        }
        
    }

    return (int)n;
}
