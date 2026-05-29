#include <stdio.h>
#include "tp_pilas.h"
#include <string.h>

Pila p_ej6_eliminarclave(Pila p, int clave){
    Pila paux = p_crear();
    Pila resaux = p_crear();
    Pila res = p_crear();

    while(!p_es_vacia(p)){
        TipoElemento te= p_desapilar(p);

        p_apilar(paux,te);

        if(te->clave!=clave){
            p_apilar(resaux,te);
        }  
    }

    while(!p_es_vacia(paux)){
        p_apilar(p,p_desapilar(paux));
    }

    while(!p_es_vacia(resaux)){
        p_apilar(res, p_desapilar(resaux));
    }

    return res;

}//O(n)

void p_ej6_eliminarclaveAux(Pila p, int clave, Pila res){

    if(p_es_vacia(p)){
        return;
    }

    TipoElemento te = p_desapilar(p);

    p_ej6_eliminarclaveAux(p, clave, res);

    p_apilar(p, te);

    if(te->clave != clave){
        p_apilar(res, te);
    }
}

Pila p_ej6_eliminarclave2(Pila p, int clave){

    Pila res = p_crear();

    p_ej6_eliminarclaveAux(p, clave, res);

    return res;
}
