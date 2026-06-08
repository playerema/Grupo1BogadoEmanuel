#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tp_colas.h"
#include "../libs/colas/headers/colas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/pilas/headers/pilas.h"

void limpiar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {

    int option = 1, seguir;

    while (option != 0) {

        printf("+---------------+ MENU +---------------+\n");
        printf("    1 - Ejercicio 2\n");
        printf("    2 - Comparar colas - Ejercicio 3\n");
        printf("    3 - Eliminar claves repetidas - Ejercicio 4\n");
        printf("    4 - Divisores - Ejercicio 5\n");
        printf("    5 - Comunes en cola y pila - Ejercicio 6\n");
        printf("    6 - Atender clientes - Ejercicio 7\n");
        printf("    0 - Salir\n");
        printf("+--------------------------------------+\n");

        printf("Seleccione una opcion (0 - 6): ");
        scanf("%d", &option);

        while (getchar() != '\n');

        switch(option) {
            

            case 0:
                // salir
                break;

            case 1:

                seguir = 1;

                while (seguir) {

                    limpiar();
                    printf("+-----+ EJERCICIO 2 +-----+\n");
                    
                    Cola c = c_crear();
                    int i = 0, x, cant;

                    while(true) {

                        printf("Ingrese cuantas claves ingresara en la cola (maximo 10 claves): ");

                        if (scanf("%d", &cant) != 1) {

                            printf("Dato invalido.\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        if (cant < 0 || cant > 10) {

                            printf("Valor fuera del rango permitido (0 - 10).\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        break;
                    }

                    while(cant != i) {

                        printf("Ingrese %d claves para la cola (%d/%d): ", cant, i, cant);
                        if (scanf("%d", &x) != 1) {

                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        c_encolar(c, te_crear(x));

                        i++;

                    }

                    int option_ej2 = 1, seguir_ej2;

                    while (option_ej2 != 0) {

                        limpiar();
                        printf("+--------+ MENU EJERCICIO 2 +--------+\n");
                        printf("    1 - Buscar clave\n");
                        printf("    2 - Insertar clave\n");
                        printf("    3 - Eliminar clave\n");
                        printf("    4 - Contar elementos\n");
                        printf("    5 - Copiar cola\n");
                        printf("    6 - Invertir cola\n");
                        printf("    0 - Salir\n");
                        printf("+------------------------------------+\n");

                        printf("Seleccione una opcion (0 - 6): ");
                        scanf("%d", &option_ej2);

                        while (getchar() != '\n');

                        switch(option_ej2) {

                            case 0:
                                seguir = 0;
                                break;

                            case 1:

                                seguir = 1;

                                while (seguir) {
                                    
                                    limpiar();
                                    printf("+-----+ Buscar clave +-----+\n\n");

                                    int cola_buscar;
                                    while(true) {

                                        printf("Ingrese una clave a buscar en la cola: ");

                                        if (scanf("%d", &cola_buscar) != 1) {

                                            printf("Dato invalido.\n\n");
                                            while(getchar() != '\n');
                                            continue;
                                        }

                                        break;
                                    }

                                    if (c_ej2_existeclave(c, cola_buscar)) printf("True\n");
                                    else printf("False\n");

                                    seguir = repetir_ejercicio();
                                }

                                break;

                            case 2:

                                seguir = 1;

                                while(seguir) {

                                    limpiar();
                                    printf("+-----+ Insertar clave +-----+\n\n");
                                    c_mostrar(c);

                                    int clave_insertar, pos_ordinal;

                                    while(true) {

                                        printf("Ingrese un entero para la clave: ");

                                        if (scanf("%d", &clave_insertar) != 1) {

                                            printf("Dato invalido.\n\n");
                                            while(getchar() != '\n');
                                            continue;
                                        }

                                        break;
                                    }

                                    while(true) {

                                        printf("Ingrese la posicion donde se insertara la clave: ");

                                        if (scanf("%d", &pos_ordinal) != 1) {

                                            printf("Dato invalido.\n\n");
                                            while(getchar() != '\n');
                                            continue;
                                        }

                                        if (pos_ordinal < 1 || pos_ordinal > 10) {

                                            printf("Valor fuera del rango permitido (1 - 10).\n\n");
                                            while(getchar() != '\n');
                                            continue;
                                        }

                                        break;
                                    }

                                    Cola c_inser = c_ej2_colarelemento(c, pos_ordinal, te_crear(clave_insertar));
                                    c_mostrar(c_inser);

                                    seguir = repetir_ejercicio();
                                }

                                break;

                            case 3:

                                seguir = 1;

                                while(seguir) {

                                    limpiar();
                                    printf("+-----+ Eliminar clave +-----+\n\n");
                                    c_mostrar(c);

                                    int clave_eliminar;

                                    while(true) {

                                        printf("Ingrese la clave a eliminar: ");

                                        if (scanf("%d", &clave_eliminar) != 1) {

                                            printf("Dato invalido.\n\n");
                                            while(getchar() != '\n');
                                            continue;
                                        }

                                        break;
                                    }

                                    Cola c_elim = c_ej2_sacarelemento(c, clave_eliminar);
                                    c_mostrar(c_elim);

                                    seguir = repetir_ejercicio();
                                }

                                break;

                            case 4:

                                seguir = 1;

                                while(seguir) {

                                    limpiar();
                                    printf("+-----+ Contar elementos +-----+\n\n");
                                    
                                    printf("hay %d elementos en la cola.\n", c_ej2_contarelementos(c));
                                    seguir = repetir_ejercicio();
                                }

                                break;

                            case 5:

                                seguir = 1;

                                while(seguir) {

                                    limpiar();
                                    printf("+-----+ Copiar cola +-----+\n\n");

                                    Cola c_copia = c_ej2_copiar(c);

                                    printf("Cola original:\n"); c_mostrar(c);
                                    printf("Cola copia:\n"); c_mostrar(c_copia);

                                    seguir = repetir_ejercicio();
                                }

                                break;

                            case 6:

                                seguir = 1;

                                while(seguir) {

                                    limpiar();
                                    printf("+-----+ Invertir cola +-----+\n\n");

                                    Cola c_inver = c_ej2_invertir(c);

                                    printf("Cola original:\n"); c_mostrar(c);
                                    printf("Cola invertida:\n"); c_mostrar(c_inver);

                                    seguir = repetir_ejercicio();
                                }

                                break;

                            default:
                                limpiar();
                                printf("Opcion invalida\n\n");
                        }
                    }
                    
                }

                limpiar();
                break;

            case 2:
                
                seguir = 1;

                while (seguir) {

                    limpiar();
                    printf("+-----+ Comparar colas - EJERCICIO 3 +-----+\n");
                    
                    Cola c1 = c_crear(); Cola c2 = c_crear();
                    int i = 0, x, cant;

                    while(true) {

                        printf("Ingrese cuantas claves ingresara en la primera cola (maximo 10 claves): ");

                        if (scanf("%d", &cant) != 1) {

                            printf("Dato invalido.\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        if (cant < 0 || cant > 10) {

                            printf("Valor fuera del rango permitido (0 - 10).\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        break;
                    }

                    while(cant != i) {

                        printf("Ingrese %d claves para la cola (%d/%d): ", cant, i, cant);
                        if (scanf("%d", &x) != 1) {

                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        c_encolar(c1, te_crear(x));

                        i++;

                    }

                    limpiar();
                    printf("+-----+ Comparar colas - EJERCICIO 3 +-----+\n");
                    printf("Primera cola cargada, "); c_mostrar(c1); printf("\n");
                    
                    i = 0;

                    while(true) {

                        printf("Ingrese cuantas claves ingresara en la segunda cola (maximo 10 claves): ");

                        if (scanf("%d", &cant) != 1) {

                            printf("Dato invalido.\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        if (cant < 0 || cant > 10) {

                            printf("Valor fuera del rango permitido (0 - 10).\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        break;
                    }

                    while(cant != i) {

                        printf("Ingrese %d claves para la cola (%d/%d): ", cant, i, cant);
                        if (scanf("%d", &x) != 1) {

                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        c_encolar(c2, te_crear(x));

                        i++;

                    }

                    limpiar();
                    printf("+-----+ Comparar colas - EJERCICIO 3 +-----+\n\n");

                    printf("Cola 1: \n"); c_mostrar(c1);
                    printf("Cola 2: \n"); c_mostrar(c2);

                    if (c_ej3_iguales(c1, c2)) printf("SI son iguales.\n");
                    else printf("NO son iguales.\n");

                    printf("Complejidad algoritmica: O(n).\n");

                    seguir = repetir_ejercicio();
                }
                
                limpiar();
                break;

            case 3:
                
                seguir = 1;

                while(seguir) {

                    limpiar();
                    printf("+-----+ Eliminar claves repetidas - EJERCICIO 4 +-----+\n\n");

                    Cola c = c_crear();
                    int i = 0, x, cant;

                    while(true) {

                        printf("Ingrese cuantas claves ingresara en la cola (maximo 10 claves): ");

                        if (scanf("%d", &cant) != 1) {

                            printf("Dato invalido.\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        if (cant < 0 || cant > 10) {

                            printf("Valor fuera del rango permitido (0 - 10).\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        break;
                    }

                    while(cant != i) {

                        printf("Ingrese %d claves para la cola (%d/%d): ", cant, i, cant);
                        if (scanf("%d", &x) != 1) {

                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        c_encolar(c, te_crear(x));

                        i++;

                    }

                    limpiar();
                    printf("+-----+ Eliminar claves repetidas - EJERCICIO 4 +-----+\n\n");
                    
                    Cola cr = c_ej4_colanorepetidos(c);

                    printf("Cola original:\n"); c_mostrar(c);
                    printf("Cola sin repeticiones:\n"); c_mostrar(cr);

                    printf("Complejidad algoritmica: O(n^2).\n");

                    seguir = repetir_ejercicio();
                }
                
                limpiar();
                break;

            case 4:

                seguir = 1;

                while (seguir) {

                    limpiar();
                    printf("+-----+ Divisores - EJERCICIO 5 +-----+\n");

                    Cola c = c_crear();
                    int i = 0, x, cant;

                    while(true) {

                        printf("Ingrese cuantas claves ingresara en la cola (maximo 10 claves): ");

                        if (scanf("%d", &cant) != 1) {

                            printf("Dato invalido.\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        if (cant < 0 || cant > 10) {

                            printf("Valor fuera del rango permitido (0 - 10).\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        break;
                    }

                    while(cant != i) {

                        printf("Ingrese %d claves mayores o iguales a 2 sin repetir para la cola (%d/%d): ", cant, i, cant);
                        if (scanf("%d", &x) != 1) {

                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        if (x < 2) {

                            printf("La clave tiene que ser mayor o igual a 2.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        Cola caux = c_crear();
                        bool encontrado = false;

                        while (!c_es_vacia(c)) {

                            TipoElemento e = c_desencolar(c);

                            if (e->clave == x) {

                                encontrado = true;
                            }

                            c_encolar(caux, e);
                        }

                        while (!c_es_vacia(caux)) c_encolar(c, c_desencolar(caux));

                        if (encontrado) {

                            printf("Clave repetida, ingrese otra clave.\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        c_encolar(c, te_crear(x));

                        i++;

                    }

                    Cola cr = c_ej5_divisortotal(c), caux = c_crear();

                    limpiar();
                    printf("+-----+ Divisores - EJERCICIO 5 +-----+\n");

                    c_mostrar(cr);
                    printf("Divisores totales ->");

                    while(!c_es_vacia(cr)) {

                        TipoElemento e = c_desencolar(cr);
                        c_encolar(caux, e);

                        if (*(bool*)e->valor == true) printf(" %d", e->clave);

                    }

                    while (!c_es_vacia(caux)) c_encolar(cr, c_desencolar(caux));

                    printf("\nDivisores parciales ->");

                    while(!c_es_vacia(cr)) {

                        TipoElemento e = c_desencolar(cr);
                        c_encolar(caux, e);

                        if (*(bool*)e->valor == false) printf(" %d", e->clave);

                    }

                    while (!c_es_vacia(caux)) c_encolar(cr, c_desencolar(caux));

                    printf("Complejidad algoritmica: O(n).\n");
                
                    seguir = repetir_ejercicio();
                }

                limpiar();
                break;

            case 5:

                seguir = 1;

                while (seguir) {

                    limpiar();
                    printf("+-----+ Comunes en cola y pila - EJERCICIO 6 +-----+\n");

                    Cola c = c_crear(); Pila p = p_crear();
                    int i = 0, x, cant;

                    while(true) {

                        printf("Ingrese cuantas claves ingresara en la cola (maximo 10 claves): ");

                        if (scanf("%d", &cant) != 1) {

                            printf("Dato invalido.\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        if (cant < 0 || cant > 10) {

                            printf("Valor fuera del rango permitido (0 - 10).\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        break;
                    }

                    while(cant != i) {

                        printf("Ingrese %d claves para la cola (%d/%d): ", cant, i, cant);
                        if (scanf("%d", &x) != 1) {

                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        c_encolar(c, te_crear(x));

                        i++;

                    }

                    limpiar();
                    printf("+-----+ Comunes en cola y pila - EJERCICIO 6 +-----+\n");
                    printf("Primera cola cargada, "); c_mostrar(c); printf("\n");
                    i = 0;

                    while(true) {

                        printf("Ingrese cuantas claves ingresara en la pila (maximo 10 claves): ");

                        if (scanf("%d", &cant) != 1) {

                            printf("Dato invalido.\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        if (cant < 0 || cant > 10) {

                            printf("Valor fuera del rango permitido (0 - 10).\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        break;
                    }

                    while(cant != i) {

                        printf("Ingrese %d claves para la pila (%d/%d): ", cant, i, cant);
                        if (scanf("%d", &x) != 1) {

                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        p_apilar(p, te_crear(x));

                        i++;

                    }

                    limpiar();
                    printf("+-----+ Comunes cola y pila - EJERCICIO 6 +-----+\n");

                    c_mostrar(c); p_mostrar(p);

                    Lista lr = c_ej6_comunesapilaycola(p, c);
                    printf("(");

                    for (int i = 0; i < l_longitud(lr); i++) {

                        TipoElemento e = l_recuperar(lr, i+1);

                        printf("%s, ", (char *)e->valor);
                    }
                    printf(")\n");

                    printf("Complejidad algoritmica: O(n^2).\n");

                    seguir = repetir_ejercicio();
                }
                
                limpiar();
                break;

            case 6:

                seguir = 1;

                while (seguir) {

                    limpiar();
                    printf("+-----+ Atender clientes - EJERCICIO 7 +-----+\n");

                    Cola c1 = c_crear(), c2 = c_crear(), c3 = c_crear();
                    int i = 0, x, cant, max = 10, Q;

                    while(true) {

                        printf("Ingrese cuantas claves ingresara en la primera cola (maximo %d claves): ", max);

                        if (scanf("%d", &cant) != 1) {

                            printf("Dato invalido.\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        if (cant < 0 || cant > max) {

                            printf("Valor fuera del rango permitido (0 - 10).\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        break;
                    }

                    while(cant != i) {

                        printf("Ingrese %d claves para la cola (%d/%d): ", cant, i, cant);
                        if (scanf("%d", &x) != 1) {

                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        c_encolar(c1, te_crear(x));

                        i++;

                    }

                    max -= cant;
                    limpiar();
                    printf("+-----+ Comparar colas - EJERCICIO 3 +-----+\n");
                    printf("Primera cola cargada.\n");
                    
                    i = 0;

                    while(max > 0) {

                        printf("Ingrese cuantas claves ingresara en la segunda cola (maximo %d claves): ", max);

                        if (scanf("%d", &cant) != 1) {

                            printf("Dato invalido.\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        if (cant < 0 || cant > max) {

                            printf("Valor fuera del rango permitido (0 - %d).\n\n", max);
                            while(getchar() != '\n');
                            continue;
                        }

                        break;
                    }

                    while(cant != i && max > 0) {

                        printf("Ingrese %d claves para la cola (%d/%d): ", cant, i, cant);
                        if (scanf("%d", &x) != 1) {

                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        c_encolar(c2, te_crear(x));

                        i++;

                    }

                    max -= cant;

                    limpiar();
                    printf("+-----+ Atender clientes - EJERCICIO 7 +-----+\n");
                    printf("segunda cola cargada.\n"); printf("\n");
                    
                    i = 0;

                    while(max > 0) {

                        printf("Ingrese cuantas claves ingresara en la tercera cola (maximo %d claves): ", max);

                        if (scanf("%d", &cant) != 1) {

                            printf("Dato invalido.\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        if (cant < 0 || cant > max) {

                            printf("Valor fuera del rango permitido (0 - %d).\n\n", max);
                            while(getchar() != '\n');
                            continue;
                        }

                        break;
                    }

                    while(cant != i && max > 0) {

                        printf("Ingrese %d claves para la cola (%d/%d): ", cant, i, cant);
                        if (scanf("%d", &x) != 1) {

                            printf("Dato invalido.\n\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        c_encolar(c3, te_crear(x));

                        i++;

                    }

                    max -= cant;

                    limpiar();
                    printf("+-----+ Atender clientes - EJERCICIO 7 +-----+\n");

                    while(true) {

                        printf("Ingrese la cantidad de minutos con la que se atendera cada cola (Q): ");

                        if (scanf("%d", &Q) != 1) {

                            printf("Dato invalido.\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        if (Q < 1) {

                            printf("Los minutos tienen que ser igual o mayor a 1.\n\n");
                            while(getchar() != '\n');
                            continue;
                        }

                        break;
                    }

                    limpiar();
                    printf("+-----+ Atender clientes - EJERCICIO 7 +-----+\n");

                    printf("Q = %d\n", Q);
                    if (!c_es_vacia(c1)) c_mostrar(c1); 
                    if (!c_es_vacia(c2)) c_mostrar(c2); 
                    if (!c_es_vacia(c3)) c_mostrar(c3);

                    Cola cr = c_ej7_atenderclientes(c1, c2, c3, Q);
                     
                    while(!c_es_vacia(cr)) {

                        TipoElemento e = c_desencolar(cr);

                        printf("%s", (char *)e->valor);

                        if (!c_es_vacia(cr)) printf(",\n");
                    }

                    printf("\n");
                    seguir = repetir_ejercicio();
                }

                limpiar();
                break;

            case 7:
                
                seguir = 1;

                while (seguir) {

                    limpiar();
                    printf("+-----+ Claves repetidas - EJERCICIO 8 +-----+\n");

                    seguir = repetir_ejercicio();
                }

                limpiar();
                break;

            default:
                limpiar();
                printf("Opcion Invalida.\n\n");

        
        }
    } 
}

