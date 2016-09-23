#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM_ARRAY 20

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona lista[TAM_ARRAY];
    inicializarArray(lista,TAM_ARRAY);

    while(seguir=='s')
    {
        printf("** Menu **\n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        if (validarRango(opcion,1,5))
        {
            switch(opcion)
            {
                case 1:
                    agregarPersona(lista);
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    borrarPersona(lista);
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    ordenarPersNombre(lista,TAM_ARRAY);
                    mostrarPersonas(lista,TAM_ARRAY);
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    mostrarPersEdad(lista,TAM_ARRAY);
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    seguir = 'n';
                    break;
            }
        }
        else
        {
            system("pause");
            system("cls");
        }


    }

    return 0;
}
