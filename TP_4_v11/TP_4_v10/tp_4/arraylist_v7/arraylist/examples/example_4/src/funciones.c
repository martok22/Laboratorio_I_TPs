
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Employee.h"
#include "../inc/funciones.h"

Employee* cargarEmpleado()
{
    Employee* empleado;
    int sectorAux, idAux;
    float salaryAux;
    char nameAux[20], lastNameAux[20];
    printf("Ingrese id del empleado: \n");
    scanf("%d",&idAux);
    printf("Ingrese nombre del empleado: \n");
    fflush(stdin);
    gets(nameAux);
    fflush(stdin);
    printf("Ingrese apellido del empleado: \n");
    gets(lastNameAux);
    fflush(stdin);
    printf("Ingrese sector del empleado: \n");
    scanf("%d",&sectorAux);
    printf("Ingrese salario del empleado: \n");
    scanf("%f",&salaryAux);
    empleado = newEmployee(idAux,nameAux,lastNameAux,salaryAux,sectorAux);
    return empleado;
}


int serializarLista (char* path, ArrayList* lista)
{
    int retorno=0;
    FILE* pArchivo;
    int i;
    int cantidad;

    if(strlen(path)>0 && lista!=NULL)
    {
        pArchivo=fopen(path,"wb");
        if(pArchivo!=NULL)
        {
            cantidad=al_len(lista);
            for(i=0; i<cantidad; i++)
            {
                fwrite(al_get(lista,i),sizeof(Employee),1,pArchivo);
            }
            retorno=1;
        }
        fclose(pArchivo);
    }
    return retorno;
}

ArrayList* deserializarLista(char* path)
{
    ArrayList* retorno=NULL;
    Employee* aux;
    FILE* pArchivo;
    pArchivo=fopen(path,"rb");
    if(pArchivo!=NULL)
    {
        retorno=al_newArrayList();
        if(strlen(path)>0)
        {
            if(pArchivo!=NULL)
            {
            while(!feof(pArchivo))
                {
                    aux = (Employee*)malloc(sizeof(Employee));
                    if(fread(aux,sizeof(Employee),1,pArchivo)==1)
                    {
                       retorno->add(retorno,aux);
                    }
                }
            }
        }
    }
    fclose(pArchivo);
    return retorno;
}
