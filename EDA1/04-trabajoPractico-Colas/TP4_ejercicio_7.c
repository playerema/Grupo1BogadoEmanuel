#include "../libs/colas/headers/colas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include <stdio.h>
#include <stdlib.h>

/**
7.	Un negocio tiene 3 ventanillas para atender a sus clientes. Los clientes forman cola en cada ventanilla.
	Un día, dos de los tres empleados que atienden las ventanillas no pueden asistir al trabajo,
	quedando uno solo para atender a las tres colas. Este empleado decide que, a medida que lleguen los clientes,
	atenderá por cierta cantidad de minutos (que denominaremos Q) a cada cola, paseándose por todas las colas equitativamente.
	Se pide que implemente un algoritmo que modele esta situación y dé como resultado el orden en que fueron atendidos los clientes.
 */
// retornar la cola con los resultados de la atenciones de los clientes.  Ver el ejemplo en el PDF del TP.
// retornar en la clave el nro de cola que lo atendio y en el void* de cada elemento los textos "Cliente 1 Cola 3", Cliente 1 Cola 2, etc.
// Segun el ejemplo el primer item de la cola seria clave: 3, void* "Cliente 1 Cola 3".
// Si las colas estan vacias, retornar cola vacia.
Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion) {

    if (c_es_vacia(c1) && c_es_vacia(c2) && c_es_vacia(c3)) return c_crear();

    int client1 = 1, client2 = 1, client3 = 1;

    Cola cr = c_crear();

    while (!c_es_vacia(c1) || !c_es_vacia(c2) || !c_es_vacia(c3)) {

        if (!c_es_vacia(c1)) {

            TipoElemento e = c_desencolar(c1);
            e->clave -= tiempoatencion;

            if (e->clave <= 0) {
                char *text = malloc(20);
                sprintf(text, "Cola 1 Cliente %d", client1);
                client1++;

                
                c_encolar(cr, te_crear_con_valor(1, text));
            } else {
                c_encolar(c1, e);
            }

            
        }

        if (!c_es_vacia(c2)) {

            TipoElemento e = c_desencolar(c2);
            e->clave -= tiempoatencion;

            if (e->clave <= 0) {
                char *text = malloc(20);
                sprintf(text, "Cola 2 Cliente %d", client2);
                client2++;

                c_encolar(cr, te_crear_con_valor(2, text));
            } else {
                c_encolar(c2, e);
            }

        }

        if (!c_es_vacia(c3)) {

            TipoElemento e = c_desencolar(c3);
            e->clave -= tiempoatencion;

            if (e->clave <= 0) {
                char *text = malloc(20);
                sprintf(text, "Cola 3 Cliente %d", client3);
                client3++;

                c_encolar(cr, te_crear_con_valor(3, text));
            } else {
                c_encolar(c3, e);
            }

        }
    }

    return cr;
}