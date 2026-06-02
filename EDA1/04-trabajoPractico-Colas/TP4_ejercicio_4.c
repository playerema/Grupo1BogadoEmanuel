#include"tp_colas.h"
#include"../libs/colas/headers/colas.h"
#include"../libs/tipoElemento/headers/tipo_elemento.h"

#include <stdio.h>

// O(n)
bool c_buscar(Cola cola, int clave)
{
    Cola cola_aux = c_crear();
    TipoElemento te;
    bool exist = false;

    while(!c_es_vacia(cola)){
        te = c_desencolar(cola);
        if(te->clave == clave){
            exist = true;
        }
        c_encolar(cola_aux, te);
    }

    while(!c_es_vacia(cola_aux)){
        te = c_desencolar(cola_aux);
        c_encolar(cola, te);
    }

    return exist;
}

//O(n^2)
Cola  c_ej4_colanorepetidos(Cola c)
{
    TipoElemento x;
    Cola colaaux = c_crear(), colaret = c_crear();

    while(!c_es_vacia(c))
    {
        x = c_desencolar(c);

        if(c_buscar(colaaux,x->clave) == false && c_buscar(c,x->clave) == false)
        {
            c_encolar(colaret, x);   
        }

        c_encolar(colaaux, x);
    }
    while(!c_es_vacia(colaaux))
    {
        x = c_desencolar(colaaux);
        c_encolar(c, x);
    }
    
    return colaret;
}
