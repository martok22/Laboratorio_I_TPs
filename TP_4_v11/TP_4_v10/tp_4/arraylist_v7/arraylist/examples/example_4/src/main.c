/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ELEMENTS 5
#include <windows.h>
#include "../testing/inc/main_test.h"
#define TEST

#include "../inc/ArrayList.h"
#include "../inc/Employee.h"
#include "../inc/funciones.h"

void printArrayListEmployee(ArrayList* lista)
{
  int i=0;
  for(i=0;i<lista->len(lista);i++)
  {
      Employee* pAux = lista->get(lista,i);
      printf("%d) ",i);
      printEmployee(pAux);
  }
}

int run2(void);

int main(void)
{
    ArrayList* lista, *lista_duplicada;
    Employee* empAux;
    int opcion, opcion_menu, opcion_menu_submenu, resultado;
    char seguir = 's';
    lista=deserializarLista("data.bin");
    if(lista!=NULL) {printf("Lista cargada desde archivo con exito.\n");}
    else {printf("Error al cargar lista desde archivo.\n");}


  while(seguir=='s')
  {
      printf("--Menu--\n\n");
    printf("1-Inicialiar lista de empleados\n");
    printf("2-Agregar empleado\n");
    printf("3-Tamaño lista\n");
    printf("4-Eliminar empleado\n");
    printf("5-¿Contiene empleado?\n");
    printf("6-Borrar todos los empleados\n");
    printf("7-¿Lista vacía?\n");
    printf("8-\"Pop\" empleado\n");
    printf("9-Clonar lista de empleados\n");
    printf("10-Ordenar lista\n");
    printf("11-¿Contiene todos? \n");
    printf("12-Imprimir lista. \n");
    printf("13-Guardar lista en archivo binario\n");
    printf("14-Salir\n");
    scanf("%d",&opcion);
     switch(opcion)
    {
        case 1:
            printf("Generando lista...\n");
            Sleep(2000);
            lista=al_newArrayList();
            printf("Lista generada.\n");
            system("pause");
            system("cls");
            break;
        case 2:
            empAux=cargarEmpleado();
            printf("1- Cargar al final\n");
            printf("2- Cargar en lugar especifico(sobreescribir)\n");
            printf("3- Cargar en lugar especifico(no-sobreescribir)\n");
            scanf("%d",&opcion_menu);
            printf("Cargando empleado...\n");
            Sleep(2000);
            if(opcion_menu==1) {lista->add(lista,empAux);}
            else if(opcion_menu==2)
            {
                printf("Ingrese indice: \n");
                scanf("%d",&opcion_menu_submenu);
                lista->set(lista,opcion_menu_submenu,empAux);
            }
            else if (opcion_menu==3)
            {
                printf("Ingrese indice: \n");
                scanf("%d",&opcion_menu_submenu);
                lista->push(lista,opcion_menu_submenu,empAux);
            }
            printf("Listo.\n");
            printArrayListEmployee(lista);
            system("pause");
            system("cls");
            break;
        case 3:
            printf("Obteniendo tamaño de lista...\n");
            Sleep(2000);
            printf("Tamaño de la lista es: %d",lista->len(lista));
            break;
        case 4:
            printf("Ingrese indice de empleado: \n");
            scanf("%d",&opcion_menu);
            printf("Borrando empleado...\n");
            Sleep(2000);
            lista->remove(lista,opcion_menu);
            printf("Lista de empleados: \n");
            printArrayListEmployee(lista);
            system("pause");
            system("cls");
            break;
        case 5:
            printf("Ingrese indice de empleado: \n");
            scanf("%d",&opcion_menu);
            printf("Contiene?...\n");
            if(lista->contains(lista,lista->get(lista,opcion_menu))) printf("SI\n");
            if(lista->contains(lista,lista->get(lista,opcion_menu))==0) printf("NO\n");
            system("pause");
            system("cls");
            break;
        case 6:
            printf("Borrando empleados...\n");
            Sleep(2000);
            resultado=lista->clear(lista);
            if(resultado==0)printf("Empleados borrados.\n");
            if(resultado==-1)printf("Error al borrar.\n");
            system("pause");
            system("cls");
            break;
        case 7:
            printf("Lista vacia?...\n");
            Sleep(2000);
            if(lista->isEmpty(lista)==1) printf("Correcto.\n");
            if(lista->isEmpty(lista)==0) printf("Incorrecto, lista no-vacia.\n");
            if(lista->isEmpty(lista)==-1) printf("Error\n");
            system("pause");
            system("cls");
            break;
       case 8:
            printf("Ingrese indice de empleado: \n");
            scanf("%d",&opcion_menu);
            printf("\nPop de empleado...\n");
            Sleep(2000);
            printf("Empleado extraido: \n");
            printEmployee(lista->pop(lista,opcion_menu));
            printf("\nLista de empleados: \n");
            printArrayListEmployee(lista);
            system("pause");
            system("cls");
            break;
       case 9:
            printf("Clonando lista...\n");
            Sleep(2000);
            lista_duplicada=lista->clone(lista);
            printf("Lista original: \n");
            printArrayListEmployee(lista);
            printf("\n\nLista duplicada: \n");
            printArrayListEmployee(lista_duplicada);
            system("pause");
            lista_duplicada->deleteArrayList(lista_duplicada);
            system("cls");
            break;
       case 10:
            printf("\n1-De menor a mayor.\n");
            printf("2-De mayor a menor.\n");
            scanf("%d",&opcion_menu);
            printf("\nOrdenando lista...\n");
            Sleep(2000);
            lista_duplicada=lista->clone(lista);
            if (opcion_menu==1)
            {
                if(!(lista_duplicada->sort(lista_duplicada, compareEmployee,1)))
                {
                    printf("Listo.\n");
                }
                else
                {
                    printf("ERROR\n");
                }
            }
            if (opcion_menu==2)
            {
                if(!(lista_duplicada->sort(lista_duplicada, compareEmployee,0)))
                {
                    printf("Listo.\n");
                }
                   else
                {
                    printf("ERROR\n");
                }
            }
            printf("Lista ordenada por salario: \n");
            printArrayListEmployee(lista_duplicada);
            system("pause");
            system("cls");
            //lista_duplicada->deleteArrayList(lista_duplicada);
            break;
        case 11:
            printf("Contiene todos los elementos?...\n");
            lista_duplicada=lista->clone(lista);
            if(lista_duplicada->containsAll(lista_duplicada,lista)) printf("SI\n");
            if(lista_duplicada->containsAll(lista_duplicada,lista)==0) printf("NO\n");
            if(lista_duplicada->containsAll(lista_duplicada,lista)==-1) printf("ERROR\n");
            system("pause");
            system("cls");
            break;
        case 12:
            printf("Imprimiendo empleados...\n");
            Sleep(2000);
            printArrayListEmployee(lista);
            system("pause");
            system("cls");
            break;
        case  13:
            printf("Guardando lista en archivo binario...\n");
            Sleep(2000);
            if (serializarLista("data.bin",lista)) printf("Serializado con exito...\n");
            system("pause");
            system("cls");
            break;
        case 14:
            seguir='n';
            system("pause");
            system("cls");
            break;
      }
  }


    //#ifdef TEST

        startTesting(1); //new
       startTesting(2); // add
        startTesting(3); //delete ArrayL
        startTesting(4); // len
        startTesting(5); // get
        startTesting(6); // al_contains
        startTesting(7); // al_set
        startTesting(8); // al_remove
        startTesting(9); // al_contain
       startTesting(10); // al_clone
       startTesting(11); // push
        startTesting(12); // index_of
        startTesting(13); // al_isEmpty
        startTesting(14); // pop
        startTesting(15);  // sublist
        startTesting(16);  // ContainedAll
        startTesting(17); // alsort*/
        //run2();


    //#else
        //run();
      //  run2();
    //#endif

    return 0;
}


int run2(void)
{
    // Genero personas para usar en el ArrayList
    Employee* p0 = newEmployee(14, "JUAN1" ,"LOPEZ", 133.22,5);
    Employee* p1 = newEmployee(14, "JUAN2" ,"LOPEZ", 233.22,5);
    Employee* p2 = newEmployee(14, "JUAN3" ,"LOPEZ", 333.22,5);
    Employee* p3 = newEmployee(14, "JUAN4" ,"LOPEZ", 433.22,5);

    printEmployee(p0);
    printEmployee(p1);
    printEmployee(p2);
    printEmployee(p3);
    //__________________________________________


    printf("\r\nCargo ArraList...\r\n");
    ArrayList* lista = al_newArrayList();
    lista->add(lista,p0);
    lista->add(lista,p1);
    lista->add(lista,p2);
    al_add(lista,p3); // forma no orientada a objetos
    printArrayListEmployee(lista);

    printf("\r\nRemuevo index 2\r\n");
    lista->remove(lista,2);
    printArrayListEmployee(lista);

    printf("\r\nContiene p0 ?\r\n");
    if(lista->contains(lista,p0))
        printf("SI");
    else
        printf("NO");

    printf("\r\nContiene p2 ?\r\n");
    if(lista->contains(lista,p2))
        printf("SI");
    else
        printf("NO");

    printf("\r\nAgrego p2 en la posicion 1\r\n");
    lista->set(lista,1,p2); // vuelvo a agregar p2
    printArrayListEmployee(lista);


    printf("\r\nClonamos array\r\n");
    ArrayList* lista2 = lista->clone(lista);
    printf("Lista original:%p\r\n",lista);
    printArrayListEmployee(lista);


    printf("Lista Clonada:%p\r\n",lista2);
    printArrayListEmployee(lista2);

    lista2->sort(lista2, compareEmployee,1);
    printf("Lista Clonada Ordenada por Edad (UP):%p\r\n",lista2);
    printArrayListEmployee(lista2);

    lista2->sort(lista2, compareEmployee,0);
    printf("Lista Clonada Ordenada por Edad (DOWN):%p\r\n",lista2);
    printArrayListEmployee(lista);

    printf("\r\nlista clonada contiene lista?:");
    if(lista->containsAll(lista,lista2))
        printf("SI");
    else
        printf("NO");


    printf("\r\n\r\nPosicion de p2:");
    int index = lista->indexOf(lista,p2);
    printf("%d\r\n",index);
    printf("\r\nPosicion de p1:");
    index = lista->indexOf(lista,p1);
    printf("%d\r\n",index);


    printf("\r\n\r\nHacemos push de p1 en la posicion 1\r\n");
    lista->push(lista,1,p1);
    printArrayListEmployee(lista);


    printf("\r\nObtenemos sub-lista de 1 a 2\r\n");
    ArrayList* subLista = lista->subList(lista,1,2);
    printArrayListEmployee(subLista);


    printf("\r\n\r\nHacemos pop de p1 en la posicion 1\r\n");
    Employee* p1Aux = lista->pop(lista,1);
    printf("Elemento pop(): %s\r\n",p1Aux->name);
    printArrayListEmployee(lista);


    printf("\r\nClear array\r\n");
    lista->clear(lista);
    printArrayListEmployee(lista);

    printf("\r\nEsta vacio?\r\n");
    if(lista->isEmpty(lista))
        printf("SI");
    else
        printf("NO");

    // Test expansion/contraccion del size
    printf("\r\n\r\nTest size\r\n");
    int j;
    for(j=0; j<1100; j++)
    {
      Employee* pAux = malloc(sizeof(Employee));
      sprintf(pAux->name,"Juan %d",j);
      pAux->salary=j;
      lista->add(lista,pAux);
    }
    printf("Cantidad de elementos:%d\r\n",lista->len(lista));
    //printArrayListPersonas(lista);
    for(j=0; j<1100; j++)
    {
      lista->pop(lista,0);
    }
    printf("Cantidad de elementos:%d\r\n",lista->len(lista));
    //printArrayListPersonas(lista);
    //____________________________________

    printf("\r\nLibero memoria y termino\r\n");
    free(p0);
    free(p1);
    free(p2);
    free(p3);
    lista->deleteArrayList(lista);
    lista2->deleteArrayList(lista2);

    system("PAUSE");
    return 0;
}



