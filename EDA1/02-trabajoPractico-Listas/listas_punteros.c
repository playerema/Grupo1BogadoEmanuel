#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "listas.h"
#include "tipo_elemento.h"

int const TAMANIO_MAXIMO = 100;

struct Nodo {
    TipoElemento datos;
    struct Nodo *siguiente;
};

struct ListaRep{
    struct Nodo *inicio;
    int cantidad;
};

typedef struct ListaRep *Lista;

struct IteradorRep {
struct Nodo *posicionActual;
};

Lista l_crear(){
    Lista l =(Lista) malloc(sizeof(struct ListaRep));
    l->cantidad=0;
    l->inicio=NULL;
    return l;
}//o(1)

bool l_es_vacia(Lista lista){return l_longitud(lista)==0;}//o(1)

bool l_es_llena(Lista lista){return l_longitud(lista)==TAMANIO_MAXIMO;}//o(1)

int l_longitud(Lista lista){return lista->cantidad;}//o(n)

bool l_agregar(Lista lista, TipoElemento elemento){
    if(l_es_llena(lista)){return false;}

    struct Nodo *n= malloc(sizeof(struct Nodo));
    n->datos=elemento;
    n->siguiente = NULL;

    struct Nodo *ultimo = lista->inicio;

    if (lista->inicio == NULL) {
        lista->inicio = n;
    } else {
        while (ultimo->siguiente!=NULL){
            ultimo= ultimo->siguiente;
        }
    
        ultimo->siguiente = n;    

    }
    lista->cantidad++;    
    return true;
}//o(n)

bool l_borrar(Lista lista, int clave){
    if(l_es_vacia(lista)){return false;}
    if(l_longitud(lista)==1 && lista->inicio->datos->clave==clave){
        lista->inicio=NULL;
        return true;
    }

    struct Nodo *nodo = lista->inicio;
    struct Nodo *sig = nodo->siguiente;
  
    while(sig->siguiente!=NULL){
        if(sig->datos->clave==clave){
            nodo->siguiente=sig->siguiente;
            sig=sig->siguiente;
            lista->cantidad--;
        }
        
        nodo=nodo->siguiente;
        sig=sig->siguiente;
    }

    if(sig->datos->clave==clave){
        nodo->siguiente=NULL;
        lista->cantidad--;
    }

    return true;
}

TipoElemento l_buscar(Lista lista, int clave){
    if(l_es_vacia(lista)){return NULL;}

    struct Nodo *n = lista->inicio;
    TipoElemento res=NULL;
    bool continuar=true;

    while(n->siguiente!=NULL && continuar){
        if(n->datos->clave==clave){
            res=n->datos;
            continuar=false;
        }

        n=n->siguiente;
    }

    if(n->datos->clave==clave && continuar){
        res=n->datos;
        continuar=false;
    }

    return res;
}



bool l_insertar(Lista lista, TipoElemento elemento, int pos){
    if(l_es_llena(lista)){return false;}
    if(pos<=0 || pos>l_longitud(lista)+1){return false;}

    //declaro el nodo a insertar
    struct Nodo *n = malloc(sizeof(struct Nodo));
    n->datos=elemento;
    n->siguiente = NULL;

    //declaro el nodo actual y el anterior con el que recorrere la lista
    struct Nodo *nodo = lista->inicio;
    struct Nodo *sig = nodo->siguiente;
    //declaro un booleano para parar el recorrido y un entero para saber la posicion actual

    if(pos==1){
        n->siguiente=nodo;
        lista->inicio=n;    
        lista->cantidad++;    
    }else if(pos==l_longitud(lista)+1){
        l_agregar(lista,elemento);
    }else{

        for(int i=1;i<=l_longitud(lista);i++){

            if(i==pos-1){
                n->siguiente=sig;
                nodo->siguiente=n;
            
                i=l_longitud(lista);
            }

            sig=sig->siguiente;
            nodo=nodo->siguiente;

        }
        lista->cantidad++;
    }

    return true;
}//o(n)

bool l_eliminar(Lista lista, int pos){
    if(l_es_vacia(lista)){return false;}
    if(pos<0 || pos>l_longitud(lista)){return false;}
    if(pos==1 && l_longitud(lista)==1){
        lista->inicio=NULL;
        lista->cantidad--;
        return true;
    }

    struct Nodo *nodo = lista->inicio;
    struct Nodo *sig = nodo->siguiente;
  
    if(pos==1){
        lista->inicio=lista->inicio->siguiente;   
        lista->cantidad--;
    }else{
        for(int i=1;i<l_longitud(lista);i++){
            if(i==pos-1){
                nodo->siguiente = sig->siguiente;
                sig = sig->siguiente;
                lista->cantidad--;
                return true;
            }
        
            nodo = nodo->siguiente;
            sig = sig->siguiente;
        }

        nodo->siguiente = NULL;
        lista->cantidad--;
    }
    return true;
}//o(n)

TipoElemento l_recuperar(Lista lista, int pos){
    if(l_es_vacia(lista)){return NULL;}
    if(pos<0 || pos>l_longitud(lista)){return NULL;}

    struct Nodo *n = lista->inicio;
    TipoElemento res=NULL;

    for(int i=1;i<=l_longitud(lista);i++){
        if(i==pos){
            res=n->datos;
            i=l_longitud(lista);
        }

        n=n->siguiente;
    }

    return res;
}

void l_mostrar(Lista lista){
    struct Nodo *inicio = lista->inicio;

    printf("mostrando lista: ");

    while(inicio->siguiente!=NULL){
        printf(" %d ",inicio->datos->clave);
        inicio = inicio->siguiente;
    }
    
    printf(" %d ",inicio->datos->clave);
}