#include <stdio.h>
#include <stdlib.h>
#include "Gonzalez.h"


// Los casos de error fueron abordados en el main, y no dentro de las funciones.
/*  Los casos de error son: división por 0, negativo para el factorial, y entrada de caracter
    en casos de ingreso por el usuario.

    En el último caso, funciona excepto cuando hay caracter después del número,
    por ej: "2aab" toma como válido el 2. "aab2" da error.

*/

int main()
{
    char seguir='s';
    int opcion;
    float A=0;
    float B=0;
    float sum, rest, multip, divi;
    int fact;
    int aux;

    while(seguir=='s')
    {

        printf("1- Ingresar 1er operando (A=%.2f)\n",A);
        printf("2- Ingresar 2do operando (B=%.2f)\n",B);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        printf("\nIngrese el numero de opcion: \n");

        fflush(stdin);
        aux = scanf("%d",&opcion);
        while (aux<=0)  // scanf devuelve 0 o num negativo cuando falla en encontrar el formato %d
        {
            fflush(stdin);
            printf("\nError, ingrese valor numerico: ");
            aux = scanf("%d",&opcion);
        }
        while(opcion>9 || opcion<1)
        {
            fflush(stdin);
            printf("\nError, reingrese entre 1 y 9: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                A=asignarA();
                printf("\nSe ha asignado %.2f a la variable A\n\n",A);
                system("pause");
                break;

            case 2:
                B=asignarB();
                printf("\nSe ha asignado %.2f a la variable B\n\n",B);
                system("pause");
                break;
            case 3:
                sum=suma(A,B);
                printf("\nLa suma de A y B es %.2f\n\n",sum);
                system("pause");
                break;
            case 4:
                rest=resta(A,B);
                printf("\nLa resta de A y B es %.2f\n\n",rest);
                system("pause");
                break;
            case 5:
                if(B!=0) // Si el divisor no es 0
                {
                    divi=division(A,B);
                    printf("\nLa division de A y B es %.2f\n\n",divi);
                }
                else
                {
                    printf("\nEl divisor (B) no puede ser 0. Asigne otro valor a B.\n");
                }
                system("pause");
                break;
            case 6:
                multip=multiplicacion(A,B);
                printf("\nLa multiplicacion de A y B es %.2f\n\n",multip);
                system("pause");
                break;
            case 7:
                if(A>=0) // Mientras A no sea negativo
                {
                    fact=factorial(A);
                    printf("\nEl factorial de A es %d\n\n",fact);
                }
                else
                {
                    printf("\nNo existe factorial de negativo; asigne valor positivo en A.\n\n");
                }
                system("pause");
                break;
            case 8:
                sum=suma(A,B);
                rest=resta(A,B);
                multip=multiplicacion(A,B);
                printf("\nLa suma de A y B es %.2f\n",sum);
                printf("La resta de A y B es %.2f\n",rest);
                printf("La multiplicacion de A y B es %.2f\n",multip);
                if (B!=0) // Si el divisor no es 0
                {
                    divi=division(A,B);
                    printf("La division de A y B es %.2f\n",divi);
                }
                else
                {
                    printf("El divisor (B) debe ser distinto de 0. Asigne nuevamente otro valor a B.\n");
                }
                if (A>=0) // Mientras A no sea negativo
                {
                    fact=factorial(A);
                    printf("El factorial de A es %d\n\n",fact);
                }
                else
                {
                    printf("No existe factorial de negativo; asigne valor positivo a A.\n\n");
                }
                system("pause");
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}

