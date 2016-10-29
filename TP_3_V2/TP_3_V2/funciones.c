#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void inicializarPeliculas(eMovie peliculas[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        peliculas[i].estado=0;
        peliculas[i].id=i;
    }
}

int agregarPelicula(eMovie peliculas[], int tam)
{
    int retorno=0, indice;
    if((indice=espacioLibrePelicula(peliculas,tam))!=-1)
    {
        //No utilice linkimagen porque no entendí como debía ingresarlo el usuario
        char auxTitulo[20], auxDescripcion[100], auxGenero[20];
        int auxPuntaje, auxDuracion;
        printf("Ingrese titulo de la pelicula: ");
        fflush(stdin);
        gets(auxTitulo);
        printf("Ingrese descripcion de la pelicula: ");
        fflush(stdin);
        gets(auxDescripcion);
        printf("Ingrese genero de la pelicula: ");
        fflush(stdin);
        gets(auxGenero);
        printf("Ingrese duracion de la pelicula: ");
        scanf("%d",&auxDuracion);
        printf("Ingrese puntaje de la pelicula: ");
        scanf("%d",&auxPuntaje);
        if (validarCadena(auxTitulo,20) && validarCadena(auxDescripcion,100) && validarCadena(auxGenero,20)
                    && validarRangoEntero(auxPuntaje,0,10) && validarPositivoEntero(auxDuracion))
        {
            strcpy(peliculas[indice].titulo,auxTitulo);
            strcpy(peliculas[indice].descripcion,auxDescripcion);
            strcpy(peliculas[indice].genero,auxGenero);
            peliculas[indice].duracion=auxDuracion;
            peliculas[indice].puntaje=auxPuntaje;
            peliculas[indice].estado=1;
            retorno=1;
        }
        else
        {
            printf("Hubo error al validar los datos ingresados. Reintente.\n");
        }
    }
    return retorno;
}

int menuPeliculas (eMovie peliculas[], int tam)
{
    int opcion;
    printf("Seleccione un nro de pelicula a borrar: \n");
    int i;
    for(i=0; i<tam; i++)
    {
        if(peliculas[i].estado==1)
        {
            printf("%d- %s\n",(i),peliculas[i].titulo);
        }

    }
    scanf("%d",&opcion);
    return opcion;
}

int espacioLibrePelicula(eMovie peliculas[], int tam)
{
    int indice=-1;
    int i;
    int flag=0;
    for (i=0; i<tam && flag==0; i++)
    {
        if(peliculas[i].estado==0)
        {
            indice=i;
            flag=1;
        }
    }
    return indice;
}

int buscarPelicula (eMovie peliculas[], int tam, int id)
{
    int indice=-1;
    int i;
    int flag=0;
    for (i=0; i<tam && flag==0; i++)
    {
        if(peliculas[i].id==id)
        {
            indice=i;
            flag=1;
        }
    }
    return indice;
}

int bajaPelicula(eMovie peliculas[], int tam)
{
    int indice, opcion, retorno=0;

    opcion=menuPeliculas(peliculas,tam);

    indice=buscarPelicula(peliculas,tam,opcion);
    if (indice!=-1)
    {
        if(peliculas[indice].estado==1)
        {
            peliculas[indice].estado=2;
            retorno=1;
        }
    }
    else
    {
        printf("No se ha encontrado la pelicula.\n");
    }
    return retorno;
}

void generarPagina(eMovie peliculas[], char nombre[], int tam)
{
    // Lo que está antes de article
    char pre_article[]="<!DOCTYPE html> <!-- Template by Quackit.com --> <html lang='en'> <head> <meta charset='utf-8'> <meta http-equiv='X-UA-Compatible' content='IE=edge'> <meta name='viewport' content='width=device-width, initial-scale=1'> <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --> <title>Lista peliculas</title> <!-- Bootstrap Core CSS --> <link href='css/bootstrap.min.css' rel='stylesheet'> <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --> <link href='css/custom.css' rel='stylesheet'> <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --> <!-- WARNING: Respond.js doesn't work if you view the page via file:// --> <!--[if lt IE 9]> <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script> <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script> <![endif]--> </head> <body>";
    // Article
    char articulo[]="<div class='container'> <div class='row'> <!-- Repetir esto para cada pelicula --><article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul><p>%s</p></article></div><!-- /.row --></div><!-- /.container -->";
    // Lo que está después de article
    char post_articulo[]="<!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>";

    FILE* pArchivo;
    int cantidadEscrita;

    pArchivo=fopen(nombre,"wb");
    if(pArchivo==NULL)
    {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    else
    {
        cantidadEscrita=fprintf(pArchivo,pre_article);
        if(cantidadEscrita<0)
        {
            printf("Error al escribir archivo.\n");
        }
        int i;
        for(i=0;i<tam;i++)
        {
            if(peliculas[i].estado==1)
            {
                cantidadEscrita=fprintf(pArchivo,articulo,peliculas[i].titulo,peliculas[i].genero,peliculas[i].puntaje,
                        peliculas[i].duracion,peliculas[i].descripcion);

                if(cantidadEscrita<0)
                {
                    printf("Error al escribir archivo.\n");
                    exit(1);
                }
            }
        }

        cantidadEscrita=fprintf(pArchivo,post_articulo);
        if(cantidadEscrita<0)
        {
            printf("Error al escribir archivo.\n");
        }
    }
    fclose(pArchivo);
}

void guardarArchivo(eMovie* peliculas, int tam, char nombre[])
{
    FILE* pArchivo;
    pArchivo=fopen(nombre,"wb");
    int i;
    for(i=0;i<tam;i++)
    {
        fwrite((peliculas+i),sizeof(eMovie),1,pArchivo);
    }
    fclose(pArchivo);
}

void leerArchivo(eMovie* peliculas, int tam, char nombre[])
{
    FILE* pArchivo;
    pArchivo=fopen(nombre,"rb");
    int i;
    for(i=0;i<tam;i++)
    {
        fread((peliculas+i),sizeof(eMovie),1,pArchivo);
    }
    fclose(pArchivo);
}

int validarCadena (char cadena[], int num)
{
    int valido=0;
    if (strlen(cadena)<=num && strlen(cadena)>0)
    {
        valido=1;
    }
    else
    {
        printf("\nLa cadena de caracteres ingresada supera el maximo de %d caracteres.\n",strlen(cadena));
    }
    return valido;
}

int validarPositivoEntero (int num)
{
    int valido=0;
    if(num>=0)
    {
        valido=1;
    }
    return valido;
}

int validarRangoEntero  (int num, int min, int max)
{
    int valido=0;
    if (min>max)
    {
        int aux;
        aux=max;
        max=min;
        min=aux;
    }
    if (num>=min && num<=max) valido=1;
    return valido;
}
