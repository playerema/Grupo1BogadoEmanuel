#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tp_1_recursividad.h"

char * ondaDigital(char seniales[]) {
    
    if(seniales[0]=='\0')
    {
        char * vacio=malloc(1);
        vacio[0]='\0';
        return vacio;
    }

    char c = seniales[0];

    char *aux=malloc(2);
    if(c=='H')
    {
        aux[0]='-';
    }
    else if (c=='L')
    {
        aux[0]='_';
    }

    aux[1]='\0';
    int len = strlen(seniales);

    char *copia = malloc(len);   // len = (len-1 chars) + '\0'
    strcpy(copia, seniales + 1);

    char *sig = ondaDigital(copia);

    free(copia);

    char *res = malloc(strlen(aux) + strlen(sig) + 2);

    strcpy(res, aux);

    if(sig[0] != '\0' && sig[0] != aux[0])
    {
        strcat(res, "|");
    }

    strcat(res, sig);

    free(aux);
    free(sig);
    
    return res;
}

int verifString(char *str, char *charPermitidos) 
{
    int i, j;
    int res = 1;
    for (i = 0; str[i] != '\0'; i++)
    {
        int encontrado = 0;
        for(j = 0; charPermitidos[j] != '\0'; j++)
        {
            if (str[i] == charPermitidos[j])
            {
                encontrado = 1;
            }
        }
        if(!encontrado)
        {
            res = 0;
        }
    }
    return res;
}

int main() {

    char seniales[50];
    int valido = 0;
    while (!valido) {
        printf("\nIngrese la senial de la onda(maximo 50 caracteres, solo H y L, ejemplo: HLHHLLHH): ");
        scanf("%s", seniales);

        if (verifString(seniales, "HL"))
        {
            valido = 1;
        } 
        else 
        {
            printf("El string contiene caracteres no permitidos. Por favor, intente de nuevo.\n");
        }
    }
    char *onda = ondaDigital(seniales);
    printf("\n%s\n\n", onda);
    free(onda);
    return 0;
}