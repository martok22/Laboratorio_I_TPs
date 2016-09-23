#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_ARRAY 20

typedef struct {

    char nombre[50];
    int edad;
    int dni;
    int estado;

}EPersona;

void inicializarArray(EPersona lista[], int tam)
{
    int i;
    for (i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }
}

void agregarPersona(EPersona lista[])
{
    char auxNombre[200];
    int auxEdad, auxDNI;
    int indice;

    printf("Ingrese un nombre (maximo 50 caracteres): ");
    fflush(stdin);
    gets(auxNombre);
    printf("\nIngrese edad: ");
    scanf("%d",&auxEdad);
    printf("\nIngrese DNI: ");
    scanf("%d",&auxDNI);
    if (validarRango(auxDNI,1,99999999)!=1 || validarRango(auxEdad,0,999)!=1 || validarNombre(auxNombre,50)!=1)
    {
        printf("\nError en un valor ingresado. No se ha añadido la persona a la base de datos.\n");
    }
    else // si fueron validado el ingreso, procede a chequear espacio
    {
        indice=obtenerEspacioLibre(lista);
        if(indice==-1)
        {
            printf("\nEl sistema se encuentra completo; no se ha podido agregar otra persona.\n");
        }
        else // si hay espacio...
        {
            if (buscarPorDni(lista,auxDNI)>-1)
            {
                printf("\nLa persona ya existe. \n");
            }
            else // si no hay otro con el mismo nombre...
            {
                strcpy(lista[indice].nombre,auxNombre);
                lista[indice].edad=auxEdad;
                lista[indice].dni=auxDNI;
                lista[indice].estado=1;
                printf("\nSe ha agregado a la persona cuyo dni es %d satisfactoriamente\n",auxDNI);
            }
        }
    }

}

int buscarPorDni(EPersona lista[], int dni)
{
    int indice=-1;
    int i;
    for(i=0; i<TAM_ARRAY; i++)
    {
        if(lista[i].dni==dni) indice=i;
    }
    return indice; // devuelve -1 si no encuentra el indice
}

int obtenerEspacioLibre(EPersona lista[])
{
    int primerEspacio=-1;
    int i;
    int flag=0;
    for(i=0; i<TAM_ARRAY; i++)
    {
        if((lista[i].estado==0) && (flag!=1))
        {
            primerEspacio=i;
            flag=1;
        }
    }
    return primerEspacio; // devuelve -1 si no encuentra el indice
}

int validarNombre (char nombre[], int maximo)
{
    int esValido=0;
    if (strlen(nombre)<maximo)
    {
        esValido=1;
    }
    else
    {
        printf("\nEl nombre es muy largo.\n");
    }
    return esValido; // devuelve 0 si no es válido.
}

int validarRango (int numero, int min, int max)
{
    int esValido=0;
    if (max>=min)
    {
        if (numero>=min && numero<=max)
        {
            esValido=1;
        }
        else
        {
            printf("\nEl numero ingresado no es valido.\n");
        }
    }
    else
    {
        printf("El maximo no puede ser menor al minimo.");
    }

    return esValido; // devuelve 0 si no es válido
}

int borrarPersona (EPersona lista[])
{
    int indiceABorrar=-1;
    int auxDNI;
    printf("\nIngrese DNI: \n");
    scanf("%d",&auxDNI);
    if (buscarPorDni(lista,auxDNI)>-1)
    {
        indiceABorrar=buscarPorDni(lista,auxDNI);
        lista[indiceABorrar].estado=2;
        printf("\nLa persona se ha eliminado con éxito.\n");
    }
    else
    {
        printf("\nNo se ha encontrado a la persona especificada a eliminar.\n");
    }
    return indiceABorrar; // devuelve indice encontrado, o -1 si no encontró
}

void mostrarPersonas (EPersona lista[])
{
    int i;
    int flag=0;
    for (i=0; i<TAM_ARRAY; i++)
    {
        if (lista[i].estado==1) flag=1;
    }
    if (flag==1) // Muestra el rótulo si hay alguna persona en la lista
    {
        printf("\n\nNombre      Edad         Dni \n");
    }
    else
    {
        printf("\n\nNo hay personas para mostrar.\n\n");
    }
    for (i=0; i<TAM_ARRAY; i++)
    {
        if (lista[i].estado==1)
        {
            printf("%-10s   %3d    %8d  \n",lista[i].nombre,lista[i].edad,lista[i].dni);
        }
    }
    printf("\n");
}

void ordenarPersNombre (EPersona lista[], int tam) // Ordena de menor a mayor alfabéticamente
{
    int i, j;
    for (i=0; i<tam; i++)
    {
        for (j=0; j<tam; j++)
        {
            if (strcmp(lista[j].nombre,lista[i].nombre)==1)
            {
                char aux[50];
                strcpy(aux,lista[i].nombre);
                strcpy(lista[i].nombre,lista[j].nombre);
                strcpy(lista[j].nombre,aux);

                int aux2;
                aux2=lista[i].dni;
                lista[i].dni=lista[j].dni;
                lista[j].dni=aux2;

                int aux3;
                aux3=lista[i].edad;
                lista[i].edad=lista[j].edad;
                lista[j].edad=aux3;

                int aux4;
                aux4=lista[i].estado;
                lista[i].estado=lista[j].estado;
                lista[j].estado=aux4;

            }
        }
    }
}

void mostrarPersEdad (EPersona lista[], int tam)
{
    int menorA18=0, mayorA18YMenorA35=0, mayorA35=0;

    int i;
    for(i=0; i<tam; i++)
    {
        if (lista[i].estado==1)
        {
            if(lista[i].edad>35)
            {
                mayorA35++;
            }
            else if(lista[i].edad<18)
            {
                menorA18++;
            }
            else
            {
                mayorA18YMenorA35++;
            }
        }

    }
    printf("\n");
    printf("\n\n");
    for(i=tam; i>0; i--)
    {
        int flag=0;


        if (menorA18-i>=0)
        {
            printf(" *");

        }
        if (mayorA18YMenorA35-i>=0)
        {
            printf(" \t*");
            flag=1;
        }
        if (mayorA35-i>=0)
        {
            if(flag==1)
            {
                printf(" \t*");
            }
            else
            {
                printf(" \t\t*");
            }
        }
        if (mayorA18YMenorA35-i>=0 || mayorA35-i>=0 || menorA18-i>=0) printf("\n");

    }
    printf("\n <18\t19-35\t>35\n\n");

}
