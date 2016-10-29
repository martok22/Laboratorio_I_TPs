#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM_PELICULAS 5

int main()
{
    char seguir='s';
    int opcion=0;
    int auxId=0;
    int i;

    eMovie peliculas[TAM_PELICULAS];
    inicializarPeliculas(peliculas,TAM_PELICULAS);
    leerArchivo(peliculas,TAM_PELICULAS,"datos.txt");
    /*for(i=0;i<TAM_PELICULAS;i++)
    {
        if(peliculas[i].estado!=0)
        {
             printf("%s %s %s %d %d %d %d",peliculas[i].titulo,peliculas[i].descripcion,peliculas[i].genero,peliculas[i].duracion,
               peliculas[i].puntaje,peliculas[i].id,peliculas[i].estado);
        }
        printf("\n pelicula %d, estado: %d, id: %d",i,peliculas[i].estado,peliculas[i].id);

    }*/

    while(seguir=='s')
    {
        printf("--MENU--\n\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);
        if(validarRangoEntero(opcion,1,4))
        {
            switch(opcion)
            {
                case 1:
                    if(agregarPelicula(peliculas,TAM_PELICULAS)==1)
                    {

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
                    guardarArchivo(peliculas,TAM_PELICULAS,"datos.txt");
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
