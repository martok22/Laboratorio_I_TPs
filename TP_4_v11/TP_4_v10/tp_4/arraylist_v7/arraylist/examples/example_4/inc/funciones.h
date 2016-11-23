#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"
#include "../inc/Employee.h"

int serializarLista (char* path, ArrayList* lista);
ArrayList* deserializarLista (char* path);
Employee* cargarEmpleado();
int modificarEmpleado(Employee* empleado);
int eliminarEmpleado(Employee* empleado, ArrayList* lista);
int eliminarDesdeHasta(Employee* empleado, ArrayList* lista);
int eliminarListaEmpleados(ArrayList* lista);
int buscarEmpleado(ArrayList* lista);
int clonarLista (ArrayList* lista);
