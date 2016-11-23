

    /*
    printf("Generando empleados...\n");
    //Sleep(2000);
    Employee* p0 = newEmployee(14, "JUAN1" ,"LOPEZ", 133.22,5);
    Employee* p1 = newEmployee(14, "JUAN2" ,"LOPEZ", 233.22,5);
    Employee* p2 = newEmployee(14, "JUAN3" ,"LOPEZ", 333.22,5);
    Employee* p3 = newEmployee(14, "JUAN4" ,"LOPEZ", 433.22,5);
    Employee* p4 = newEmployee(14, "JUAN5" ,"LOPEZ", 533.22,5);
    Employee* p5 = newEmployee(1,"a","b",5,5);
/*
    printf("Generando nueva lista... Cargando nueva lista\n");
    //Sleep(2000);
    ArrayList* lista = al_newArrayList();
    lista->add(lista,p0);
    lista->add(lista,p1);
    lista->add(lista,p2);
    lista->add(lista,p3);
    lista->add(lista,p4);

    printf("Imprimo empleados...\n");
    int i;
    for(i=0; i<ELEMENTS; i++)
    {
       printf("Id: %d, Nombre: %s, Apellido: %s, Salario: %f, Sector: %d\n",((Employee*)(al_get(lista,i)))->id,((Employee*)(al_get(lista,i)))->name,((Employee*)(al_get(lista,i)))->lastName,((Employee*)(al_get(lista,i)))->salary,((Employee*)(al_get(lista,i)))->sector);
    }
    printf("Serializando...\n");

    ArrayList* lista2 = al_newArrayList();

    Sleep(2000);
    if (serializarLista("data.bin",lista))
    {
        printf("Serializado con exito...\n");
    }
    for(i=0;i<ELEMENTS;i++)
    {
        printf("id: %d",((Employee*)(lista->get(lista,i)))->id);
    }

    printf("Deserializando...\n");

    lista2=deserializarLista("data.bin");
    printf("%p\n",lista2);
    printf("Id: %d",((Employee*)lista2->get(lista2,0))->id);
*/
    /*printf("Ingresando empleado...\n");
    if(cargarEmpleado(p5)) printf("Empleado cargado con exito\n");
    printf("sector: %d",p5->sector);
    free(p5);
    free(p4);
    free(p1);
    free(p2);
    free(p3);
    free(p0);*/
//    free(lista);
  //  free(lista2);

  //  Modulito para testear expand, contract. Descomentar expand/contract para probar uno o el otro.

        /*ArrayList* lista = al_newArrayList();
        int i;
        int enteros[5];
        for(i=0;i<5;i++)
        {
            enteros[i]=i;
        }
        for(i=0;i<6;i++)
        {
            al_add(lista,&enteros[i]);
            printf("elemento %d: %d\n",i,*((int*)(lista->pElements[i])));
        }
        //expand(lista,3);
        contract(lista,3);
        for(i=0;i<6;i++)
        {
            printf("elemento %d: %d\n",i,*((int*)(lista->pElements[i])));
        }
        */
