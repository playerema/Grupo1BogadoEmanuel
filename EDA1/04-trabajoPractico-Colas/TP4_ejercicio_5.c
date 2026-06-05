#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include "./libs\tp_colas.h"
#include "./libs\colas_arreglos.c"
#include "./libs\tipo_elemento.c"

int c_longitud(Cola c){
    int res=0;
    Cola aux = c_crear();
    
    while(!c_es_vacia(c)){
        c_encolar(aux,c_desencolar(c));
        res++;
    }

    while(!c_es_vacia(aux)){
        c_encolar(c,c_desencolar(aux));
    }
    return res;
}

int maximo(Cola c){
    if(c_es_vacia(c)){return 0;}
    int res = INT_MIN;
    Cola caux = c_crear();

    while(!c_es_vacia(c)){
        TipoElemento te = c_desencolar(c);
        c_encolar(caux,te);

        if(res<te->clave){
            res=te->clave;
        }
    }

    while(!c_es_vacia(caux)){
        c_encolar(c,c_desencolar(caux));
    }

    return res;
}

Cola c_ej5_divisortotal(Cola c){
    Cola res = c_crear();
    
    if(c_es_vacia(c)){return res;}//sí esta vacia debes devolver la cola vacia

    Cola caux = c_crear();
    Cola caux2 = c_crear();
    Cola caux3 = c_crear();
    int max=c_longitud(c);

    while (!c_es_vacia(c)){//copiar la cola en tres colas diferentes
        TipoElemento te= c_desencolar(c);
        c_encolar(caux,te);//cola de divisores
        c_encolar(caux2,te);//cola de dividendos   
        c_encolar(caux3,te);//cola de restauracion
    }

    for(int i=0;i<max;i++){
        Cola caux4=c_crear();
        TipoElemento te = c_desencolar(caux);//toma un elemento del inicio
        int n=0;

        if(te->clave==0){
            n=0;
        }

        while(!c_es_vacia(caux2)){
            TipoElemento te2 = c_desencolar(caux2);

            if(te->clave!=0 && te2->clave%te->clave==0){
                n++;
            }

            c_encolar(caux4,te2);
        }

        for(int i=0;i<max;i++){
            c_encolar(caux2,c_desencolar(caux4));
        }

        if(n > max/2){
            bool* b = malloc(sizeof(bool));
            if(n==max){*b=true;}else{*b=false;}
            te->valor=b;

            c_encolar(res,te);
        }
        
    }

    while(!c_es_vacia(caux3)){//restauras la cola original
        c_encolar(c,c_desencolar(caux3));
    }

    return res;
}

int main(){
    Cola c=c_crear();

    c_encolar(c,te_crear(8));
    c_encolar(c,te_crear(12));
    c_encolar(c,te_crear(4));
    c_encolar(c,te_crear(2));
    c_encolar(c,te_crear(6));

     c_mostrar(c);

    Cola j = c_ej5_divisortotal(c);

    c_mostrar(j);
    printf("%d\n",*(bool*)c_desencolar(j)->valor);
    printf("%d\n",*(bool*)c_desencolar(j)->valor);

    return 0;
}
