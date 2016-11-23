#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Employee.h"

int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{

    if(((Employee*)pEmployeeA)->salary > ((Employee*)pEmployeeB)->salary)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->salary < ((Employee*)pEmployeeB)->salary)
    {
        return -1;
    }
    return 0;


}

void printEmployee(Employee* p)
{
    printf("Nombre:%s Salario:%.2f\r\n",p->name,p->salary);
}



/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector)
{
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        pEmployee->id = id;
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->lastName,lastName);
        pEmployee->salary = salary;
        pEmployee->sector = sector;
        pEmployee->isEmpty = 0;
        returnAux = pEmployee;
    }

    return returnAux;

}

int setEmployeeId(Employee* empleado, int id)
{
    int retorno=-1;
    if(empleado!=NULL && id>=0)
    {
        empleado->id=id;
        retorno=0;
    }
    return retorno;
}

int setEmployeeSector(Employee* empleado, int sector)
{
    int retorno=-1;
    if(empleado!=NULL && sector>0)
    {
        empleado->sector=sector;
        retorno=0;
    }
    return retorno;
}

int setEmployeeSalary(Employee* empleado, float salary)
{
    int retorno=-1;
    if(empleado!=NULL && salary>=0)
    {
        empleado->salary=salary;
        retorno=0;
    }
    return retorno;
}

int setEmployeeName(Employee* empleado, char* name)
{
    int retorno=-1;
    if(empleado!=NULL && name!=NULL && strlen(name)<51)
    {
        strcpy(empleado->name,name);
        retorno=0;
    }
    return retorno;
}

int setEmployeeLastName(Employee* empleado, char* lastName)
{
    int retorno=-1;
    if(empleado!=NULL && lastName!=NULL && strlen(lastName)<51)
    {
        strcpy(empleado->lastName,lastName);
        retorno=0;
    }
    return retorno;
}

