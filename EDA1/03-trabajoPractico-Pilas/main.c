#include "../libs/pilas/headers/pilas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "tp_pilas.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define salto printf("\n")

// Función auxiliar para limpiar la pantalla según el Sistema Operativo
void limpiar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Validador robusto de entrada de datos enteros (basado en tu main.c de guía)
int leer_entero(const char* mensaje) {
    int numero;
    int result;
    while (1) {
        printf("%s", mensaje);
        result = scanf("%d", &numero);

        if (result != 1) {
            printf("Error: Debe ingresar un numero entero valido.\n\n");
            while (getchar() != '\n'); // Limpiar el buffer
            continue;
        }

        int c = getchar();
        if (c != '\n' && c != EOF) {
            printf("Error: Entrada invalida. No inserte caracteres adicionales.\n\n");
            while (getchar() != '\n'); // Limpiar el buffer
            continue;
        }

        return numero;
    }
}

// Carga manual que permite explícitamente ingresar pilas VACÍAS
void cargar_pila_manual(Pila p, const char* nombre_pila) {
    printf("--- Carga de %s (Maximo %d elementos) ---\n", nombre_pila, TAMANIO_MAXIMO);
    printf("Nota: Si desea que la pila este VACIA, ingrese -1 inmediatamente.\n");
    
    while (!p_es_llena(p)) {
        int num = leer_entero("Ingrese una clave entera (-1 para finalizar): ");
        if (num == -1) {
            break;
        }
        p_apilar(p, te_crear(num));
    }
    
    if (p_es_vacia(p)) {
        printf("-> %s configurada como PILA VACIA.\n", nombre_pila);
    } else if (p_es_llena(p)) {
        printf("-> Se alcanzo el limite maximo de la pila.\n");
    }
    salto;
}

// Carga automática para el Ejercicio 2 (Pila con valores al azar)
void cargar_pila_aleatoria(Pila p) {
    // Genera una cantidad aleatoria de elementos (entre 3 y 7)
    int cantidad = 3 + rand() % 5; 
    for (int i = 0; i < cantidad && !p_es_llena(p); i++) {
        p_apilar(p, te_crear(1 + rand() % 50)); // Claves del 1 al 50
    }
}

int main() {
    srand(time(NULL));
    int opcion;

    do {
        printf("+--------+ MENU PRINCIPAL - TP PILAS +--------+\n");
        printf("    2 - Ejercicio 2 (Operaciones varias / Pila al azar)\n");
        printf("    3 - Ejercicio 3 (Determinar si dos pilas son iguales)\n");
        printf("    4 - Ejercicio 4 (Conversor de base decimal)\n");
        printf("    5 - Ejercicio 5 (Invertir el contenido de una pila)\n");
        printf("    6 - Ejercicio 6 (Eliminar ocurrencias de un item)\n");
        printf("    7 - Ejercicio 7 (Elementos en comun entre dos pilas)\n");
        printf("    8 - Ejercicio 8 (Sacar repeticiones y contar frecuencias)\n");
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
                
                printf("Pila original generada al azar:\n");
                p_mostrar(p2);
                salto;

                int sub_opcion;
                do {
                    printf("--- Submenu Ejercicio 2 ---\n");
                    printf("  1. Buscar una clave (a)\n");
                    printf("  2. Insertar nuevo elemento en posicion ordinal (b)\n");
                    printf("  3. Eliminar primera ocurrencia de una clave (c)\n");
                    printf("  4. Intercambiar dos posiciones ordinales (d)\n");
                    printf("  5. Duplicar el contenido de la pila (e)\n");
                    printf("  6. Contar los elementos de la pila (f)\n");
                    printf("  0. Volver al menu principal\n");
                    
                    sub_opcion = leer_entero("Seleccione una operacion: ");
                    salto;

                    switch (sub_opcion) {
                        case 1: {
                            int clave = leer_entero("Ingrese la clave a buscar: ");
                            if (p_ej2_existeclave(p2, clave)) {
                                printf("Resultado: La clave %d EXISTE en la pila.\n", clave);
                            } else {
                                printf("Resultado: La clave %d NO existe en la pila.\n", clave);
                            }
                            break;
                        }
                        case 2: {
                            int pos = leer_entero("Ingrese la posicion ordinal destino: ");
                            int clave = leer_entero("Ingrese la clave del nuevo elemento: ");
                            // Validar que la posición sea coherente internamente
                            if (pos < 1) {
                                printf("Error: La posicion ordinal debe ser mayor o igual a 1.\n");
                            } else {
                                Pila p_res = p_ej2_colocarelemento(p2, pos, te_crear(clave));
                                printf("Resultado de la pila modificada:\n");
                                p_mostrar(p_res);
                            }
                            break;
                        }
                        case 3: {
                            int clave = leer_entero("Ingrese la clave a eliminar: ");
                            Pila p_res = p_ej2_eliminarclave(p2, clave);
                            printf("Resultado de la pila modificada:\n");
                            p_mostrar(p_res);
                            break;
                        }
                        case 4: {
                            int pos1 = leer_entero("Ingrese la primera posicion ordinal: ");
                            int pos2 = leer_entero("Ingrese la segunda posicion ordinal: ");
                            if (pos1 < 1 || pos2 < 1) {
                                printf("Error: Las posiciones deben ser mayores o iguales a 1.\n");
                            } else {
                                Pila p_res = p_ej2_intercambiarposiciones(p2, pos1, pos2);
                                printf("Resultado del intercambio:\n");
                                p_mostrar(p_res);
                            }
                            break;
                        }
                        case 5: {
                            Pila p_dup = p_ej2_duplicar(p2);
                            printf("Resultado - Pila duplicada:\n");
                            p_mostrar(p_dup);
                            break;
                        }
                        case 6: {
                            int cant = p_ej2_cantidadelementos(p2);
                            printf("Resultado: La cantidad de elementos en la pila es %d.\n", cant);
                            break;
                        }
                        case 0:
                            break;
                        default:
                            printf("Opcion invalida en el submenu.\n");
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

                printf("Muestreo de las pilas ingresadas:\n");
                printf("Pila 1: "); p_mostrar(p3_1);
                printf("Pila 2: "); p_mostrar(p3_2);
                salto;

                if (p_ej3_iguales(p3_1, p3_2)) {
                    printf("Resultado: Las pilas son IGUALES.\n");
                } else {
                    printf("Resultado: Las pilas NO son iguales.\n");
                }
                salto;
                break;
            }

            case 4: {
                limpiar();
                printf("+-----+ EJERCICIO 4 +-----+\n");
                int decimal = leer_entero("Ingrese el numero decimal (positivo o 0): ");
                
                if (decimal < 0) {
                    printf("Error: Debe ingresar un numero mayor o igual a cero.\n\n");
                    break;
                }

                int base = leer_entero("Ingrese la base de destino (entre 2 y 16): ");
                if (base < 2 || base > 16) {
                    printf("Error: Base invalida. Debe estar en el rango [2 - 16].\n\n");
                    break;
                }
                
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

                printf("Pila cargada inicialmente: "); 
                p_mostrar(p5);

                Pila p5_invertida = p_ej5_invertir(p5);
                printf("Pila invertida resultante: "); 
                p_mostrar(p5_invertida);
                salto;
                break;
            }

            case 6: {
                limpiar();
                printf("+-----+ EJERCICIO 6 +-----+\n");
                Pila p6 = p_crear();
                cargar_pila_manual(p6, "Pila Original");

                printf("Pila cargada inicialmente: "); 
                p_mostrar(p6);

                int clave_eliminar = leer_entero("Ingrese la clave a remover por completo: ");
                
                Pila p6_resultado = p_ej6_eliminarclave(p6, clave_eliminar);
                printf("Pila resultante sin la clave %d: ", clave_eliminar); 
                p_mostrar(p6_resultado);
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

                printf("Pila original cargada: "); 
                p_mostrar(p8);

                Pila p8_sin_rep = p_ej8_sacarrepetidos(p8);
                printf("Pila resultante (Claves unicas y sus frecuencias): "); 
                p_mostrar(p8_sin_rep);
                salto;
                break;
            }

            default:
                limpiar();
                printf("Opcion invalida. Por favor, seleccione un ejercicio del 2 al 8.\n\n");
                break;
        }

    } while (opcion != 0);

    return 0;
}
