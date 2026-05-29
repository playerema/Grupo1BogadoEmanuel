#include "tp_pilas.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

#include <stdio.h>

// O(n)
bool p_buscar(Pila pila, int num){
    Pila pila_aux = p_crear();
    TipoElemento te;
    bool exist = false;

    while(!p_es_vacia(pila)){
        te = p_desapilar(pila);
        if(te->clave == num){
            exist = true;
        }
        p_apilar(pila_aux, te);
    }

    while(!p_es_vacia(pila_aux)){
        te = p_desapilar(pila_aux);
        p_apilar(pila, te);
    }

    return exist;
}

// O(n^2)
Pila p_ej7_elementoscomunes(Pila p1, Pila p2)
{
    Pila paux = p_crear(), pret = p_crear();
    TipoElemento x;

    while(!p_es_vacia(p1))
    {
        x = p_desapilar(p1);
        
        if((p_buscar(p2, x->clave) == true) && p_buscar(pret, x->clave) == false) 
        {
            p_apilar(pret, x);
        }

        p_apilar(paux, x);
    }
    
    while(!p_es_vacia(paux))
    {
        TipoElemento x = p_desapilar(paux);
        p_apilar(p1, x);
    }
    return pret;
}
