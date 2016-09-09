#include <stdio.h>
#include <stdlib.h>

/** \brief Pide un n�mero al usuario, y guarda a la variable A.
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
/** \brief Pide un n�mero al usuario, y guarda a la variable B.
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
 * \param primer n�mero a sumar
 * \param segundo n�mero a sumar
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
 * \param primer n�mero
 * \param segundo n�mero
 * \return El resultado de la resta
 *
 */
float resta(float a, float b)
{
    float resta;
    resta = a-b;
    return resta;
}
/** \brief Calcula la multiplicaci�n de dos numeros.
 *
 * \param Primer n�mero a multiplicar
 * \param Segundo n�mero a multiplicar
 * \return El resultado de la multiplicaci�n
 *
 */
float multiplicacion(float a, float b)
{
    float multip;
    multip = a*b;
    return multip;
}
/** \brief Calcula la divisi�n de dos n�meros. El primero es el dividendo
 * \param Primer n�mero o dividendo
 * \param Segundo n�mero o divisor
 * \return El cociente de la divisi�n.
 *
 */
float division(float a, float b)
{
    float division;
    division = a/b;
    return division;
}
/** \brief Calcula el factorial (entero) de un numero. Transforma a entero antes de realizar el c�lculo.
 *
 * \param N�mero a calcular su factorial.
 * \return El factorial (entero) del n�mero. Informa del redondeo
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

