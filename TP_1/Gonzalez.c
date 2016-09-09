#include <stdio.h>
#include <stdlib.h>

/** \brief Pide un número al usuario, y guarda a la variable A.
 * \return Devuelve el valor asignado.
 */
float asignarA()
{
    float a;
    int aux;
    fflush(stdin);
    printf("Ingrese el primer valor: ");
    aux = scanf("%f",&a);
        while (aux<=0)  // scanf devuelve 0 o num negativo cuando falla en encontrar el formato %d
        {
            fflush(stdin);
            printf("\nError, ingrese valor numerico: ");
            aux = scanf("%f",&a);
        }
    return a;
}
/** \brief Pide un número al usuario, y guarda a la variable B.
 * \return Devuelve el valor asignado.
 */
float asignarB()
{
    float b;
    int aux;
    fflush(stdin);
    printf("Ingrese el segundo valor: ");
    aux = scanf("%f",&b);
        while (aux<=0)  // scanf devuelve 0 o num negativo cuando falla en encontrar el formato %d
        {
            fflush(stdin);
            printf("\nError, ingrese valor numerico: ");
            aux = scanf("%f",&b);
        }
    return b;
}
/** \brief Calcula la suma de dos numeros. Muestra el resultado.
 *
 * \param primer número a sumar
 * \param segundo número a sumar
 * \return el resultado de la suma
 *
 */
float suma(float a, float b)
{
    float suma;
    suma = a+b;
    return suma;
}
/** \brief Calcula la resta del primer numero por el segundo.
 *
 * \param primer número
 * \param segundo número
 * \return El resultado de la resta
 *
 */
float resta(float a, float b)
{
    float resta;
    resta = a-b;
    return resta;
}
/** \brief Calcula la multiplicación de dos numeros.
 *
 * \param Primer número a multiplicar
 * \param Segundo número a multiplicar
 * \return El resultado de la multiplicación
 *
 */
float multiplicacion(float a, float b)
{
    float multip;
    multip = a*b;
    return multip;
}
/** \brief Calcula la división de dos números. El primero es el dividendo
 * \param Primer número o dividendo
 * \param Segundo número o divisor
 * \return El cociente de la división.
 *
 */
float division(float a, float b)
{
    float division;
    division = a/b;
    return division;
}
/** \brief Calcula el factorial (entero) de un numero. Transforma a entero antes de realizar el cálculo.
 *
 * \param Número a calcular su factorial.
 * \return El factorial (entero) del número. Informa del redondeo
 *
 */
int factorial(float a)
{
    printf("\nSe redondeara el numero %.2f a %d para realizar el factorial.\n\n",a,(int)a);
    a=(int)a;
    int fact=1;
    while(a>0)
        {
            fact=fact*a;
            a--;
        }

    return fact;
}

