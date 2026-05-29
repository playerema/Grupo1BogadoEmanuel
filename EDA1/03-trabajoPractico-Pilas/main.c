#include "../libs/pilas/headers/pilas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "tp_pilas.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define salto printf("\n")

// Función auxiliar para limpiar la consola según el OS
void limpiar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Función de validación para la entrada de números enteros
int leer_entero(const char* mensaje) {
    int numero;
    int result;
    while (1) {
        printf("%s", mensaje);
        result = scanf("%d", &numero);

        if (result != 1) {
            printf("Error: Debe ingresar un numero entero valido.\n\n");
            while (getchar() != '\n'); // Limpiar buffer
            continue;
        }

        int c = getchar();
        if (c != '\n' && c != EOF) {
            printf("Error: Entrada invalida. No inserte caracteres adicionales.\n\n");
            while (getchar() != '\n'); // Limpiar buffer
            continue;
        }

        return numero;
    }
}

// Carga manual de una pila controlando que no supere el tamaño máximo
void cargar_pila_manual(Pila p, const char* nombre_pila) {
    printf("--- Carga de %s (Maximo %d elementos) ---\n", nombre_pila, TAMANIO_MAXIMO);
    while (!p_es_llena(p)) {
        int num = leer_entero("Ingrese una clave entera (-1 para finalizar la carga): ");
        if (num == -1) {
            if (p_es_vacia(p)) {
                printf("La pila no puede quedar vacia. Ingrese al menos un elemento.\n\n");
                continue;
            }
            break;
        }
        p_apilar(p, te_crear(num));
    }
    if (p_es_llena(p)) {
        printf("Se ha alcanzado el limite maximo de elementos de la pila.\n");
    }
    salto;
}

// Carga una pila con valores aleatorios como pide el Ejercicio 2
void cargar_pila_aleatoria(Pila p) {
    // Genera entre 5 y 10 elementos al azar
    int cantidad = 5 + rand() % 6; 
    for (int i = 0; i < cantidad && !p_es_llena(p); i++) {
        p_apilar(p, te_crear(1 + rand() % 20));
    }
}

int main() {
    srand(time(NULL));
    int opcion;

    do {
        printf("+--------+ MENU PRINCIPAL - TP PILAS +--------+\n");
        printf("    2 - Ejercicio 2 (Operaciones varias sobre Pila azar)\n");
        printf("    3 - Ejercicio 3 (Determinar si dos pilas son iguales)\n");
        printf("    4 - Ejercicio 4 (Conversor de base decimal a otra base)\n");
        printf("    5 - Ejercicio 5 (Invertir el contenido de una pila)\n");
        printf("    6 - Ejercicio 6 (Eliminar todas las ocurrencias de un item)\n");
        printf("    7 - Ejercicio 7 (Elementos en comun entre dos pilas)\n");
        printf("    8 - Ejercicio 8 (Sacan repeticiones y contar frecuencias)\n");
        printf("    0 - Salir\n");
        printf("+---------------------------------------------+\n");
        
        opcion = leer_entero("Seleccione una opcion (0 - 8): ");

        switch (opcion) {
            case 0:
                printf("Saliendo del programa...\n");
                break;

            case 2: {
                limpiar();
                printf("+-----+ EJERCICIO 2 +-----+\n");
                Pila p2 = p_crear();
                cargar_pila_aleatoria(p2);
                
                printf("Pila original generada al azar: ");
                p_mostrar(p2);
                salto;

                int sub_opcion;
                do {
                    printf("--- Submenu Ejercicio 2 ---\n");
                    printf("1. Buscar una clave (a)\n");
                    printf("2. Insertar nuevo elemento en posicion ordinal (b)\n");
                    printf("3. Eliminar primera ocurrencia de una clave (c)\n");
                    printf("4. Intercambiar dos posiciones ordinales (d)\n");
                    printf("5. Duplicar el contenido de la pila (e)\n");
                    printf("6. Contar los elementos de la pila (f)\n");
                    printf("0. Volver al menu principal\n");
                    
                    sub_opcion = leer_entero("Seleccione una operacion: ");
                    salto;

                    switch (sub_opcion) {
                        case 1: {
                            int clave = leer_entero("Ingrese la clave a buscar: ");
                            if (p_ej2_existeclave(p2, clave)) {
                                printf("La clave %d EXISTE en la pila.\n", clave);
                            } else {
                                printf("La clave %d NO existe en la pila.\n", clave);
                            }
                            break;
                        }
                        case 2: {
                            int pos = leer_entero("Ingrese la posicion ordinal: ");
                            int clave = leer_entero("Ingrese la clave del nuevo elemento: ");
                            Pila p_res = p_ej2_colocarelemento(p2, pos, te_crear(clave));
                            printf("Resultado: ");
                            p_mostrar(p_res);
                            break;
                        }
                        case 3: {
                            int clave = leer_entero("Ingrese la clave a eliminar: ");
                            Pila p_res = p_ej2_eliminarclave(p2, clave);
                            printf("Resultado: ");
                            p_mostrar(p_res);
                            break;
                        }
                        case 4: {
                            int pos1 = leer_entero("Ingrese la primera posicion ordinal: ");
                            int pos2 = leer_entero("Ingrese la segunda posicion ordinal: ");
                            Pila p_res = p_ej2_intercambiarposiciones(p2, pos1, pos2);
                            printf("Resultado: ");
                            p_mostrar(p_res);
                            break;
                        }
                        case 5: {
                            Pila p_dup = p_ej2_duplicar(p2);
                            printf("Pila duplicada: ");
                            p_mostrar(p_dup);
                            break;
                        }
                        case 6: {
                            int cant = p_ej2_cantidadelementos(p2);
                            printf("La cantidad de elementos en la pila es: %d\n", cant);
                            break;
                        }
                        case 0:
                            break;
                        default:
                            printf("Opcion invalida.\n");
                    }
                    salto;
                } while (sub_opcion != 0);
                
                limpiar();
                break;
            }

            case 3: {
                limpiar();
                printf("+-----+ EJERCICIO 3 +-----+\n");
                Pila p3_1 = p_crear();
                Pila p3_2 = p_crear();
                
                cargar_pila_manual(p3_1, "Pila 1");
                cargar_pila_manual(p3_2, "Pila 2");

                printf("Pila 1: "); p_mostrar(p3_1);
                printf("Pila 2: "); p_mostrar(p3_2);
                salto;

                if (p_ej3_iguales(p3_1, p3_2)) {
                    printf("Resultado: Las pilas son exactamente IGUALES por su clave.\n");
                } else {
                    printf("Resultado: Las pilas NO son iguales.\n");
                }
                
                // Mostrar que no se destruyeron
                printf("Verificacion post-operacion:\n");
                printf("Pila 1 original: "); p_mostrar(p3_1);
                printf("Pila 2 original: "); p_mostrar(p3_2);
                salto;
                break;
            }

            case 4: {
                limpiar();
                printf("+-----+ EJERCICIO 4 +-----+\n");
                int decimal = leer_entero("Ingrese el numero decimal a transformar: ");
                int base = leer_entero("Ingrese la base de destino (2 al 16): ");
                
                char* resultado_base = p_ej4_cambiarbase(decimal, base);
                printf("Resultado de la conversion: %s\n", resultado_base);
                salto;
                break;
            }

            case 5: {
                limpiar();
                printf("+-----+ EJERCICIO 5 +-----+\n");
                Pila p5 = p_crear();
                cargar_pila_manual(p5, "Pila Original");

                printf("Pila cargada: "); 
                p_mostrar(p5);

                Pila p5_invertida = p_ej5_invertir(p5);
                printf("Pila invertida resultante: "); 
                p_mostrar(p5_invertida);

                printf("Pila original (no debe perderse): "); 
                p_mostrar(p5);
                salto;
                break;
            }

            case 6: {
                limpiar();
                printf("+-----+ EJERCICIO 6 +-----+\n");
                Pila p6 = p_crear();
                cargar_pila_manual(p6, "Pila Original");

                printf("Pila cargada: "); 
                p_mostrar(p6);

                int clave_eliminar = leer_entero("Ingrese la clave cuyas ocurrencias desea eliminar: ");
                
                Pila p6_resultado = p_ej6_eliminarclave(p6, clave_eliminar);
                printf("Pila resultante sin el item: "); 
                p_mostrar(p6_resultado);

                printf("Pila original (no debe perderse): "); 
                p_mostrar(p6);
                salto;
                break;
            }

            case 7: {
                limpiar();
                printf("+-----+ EJERCICIO 7 +-----+\n");
                Pila p7_1 = p_crear();
                Pila p7_2 = p_crear();

                cargar_pila_manual(p7_1, "Pila 1");
                cargar_pila_manual(p7_2, "Pila 2");

                printf("Pila 1: "); p_mostrar(p7_1);
                printf("Pila 2: "); p_mostrar(p7_2);
                salto;

                Pila p7_comunes = p_ej7_elementoscomunes(p7_1, p7_2);
                printf("Pila resultante con elementos en comun: "); 
                p_mostrar(p7_comunes);
                salto;
                break;
            }

            case 8: {
                limpiar();
                printf("+-----+ EJERCICIO 8 +-----+\n");
                Pila p8 = p_crear();
                cargar_pila_manual(p8, "Pila con Repetidos");

                printf("Pila original: "); 
                p_mostrar(p8);

                Pila p8_sin_rep = p_ej8_sacarrepetidos(p8);
                printf("Pila resultante (unicos y sus frecuencias): "); 
                p_mostrar(p8_sin_rep);
                salto;
                break;
            }

            default:
                limpiar();
                printf("Opcion invalida. Por favor, seleccione una opcion del 0 al 8.\n\n");
                break;
        }

    } while (opcion != 0);

    return 0;
}
