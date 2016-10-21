#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM_PELICULAS 20

int main()
{
    char seguir='s';
    int opcion=0;
    int auxId=0;

    eMovie peliculas[TAM_PELICULAS];
    inicializarPeliculas(peliculas,TAM_PELICULAS);

    while(seguir=='s')
    {
        printf("--MENU--\n\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);
        int i;
        if(validarRangoEntero(opcion,1,4))
        {
            switch(opcion)
            {
                case 1:
                    if(agregarPelicula(peliculas,TAM_PELICULAS)==1)
                    {
                        peliculas[auxId].id=(auxId+1);
                        auxId++;
                    }
                    else
                    {
                        printf("Hubo error al cargar pelicula\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    if((bajaPelicula(peliculas,TAM_PELICULAS))==1)
                    {
                        printf("Pelicula borrada con exito.\n");
                    }
                    else
                    {
                        printf("No se ha podido borrar la pelicula\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    generarPagina(peliculas,"peliculas.html",TAM_PELICULAS);
                    system("pause");
                    system("cls");
                   break;
                case 4:
                    seguir = 'n';
                    break;
            }
        }
        else
        {
            printf("Ingrese nro de opcion valido");
        }

    }

    return 0;
}
