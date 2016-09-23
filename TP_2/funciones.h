#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int dni;
    int estado;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */

int buscarPorDni(EPersona[], int);

 /** \brief Inicializa el campo 'estado' de todos los elementos de la lista en 0
  * \param Array de estructura tipo Persona
  * \param Tama�o del Array
  */

void inicializarArray(EPersona[], int);

 /** \brief Agrega un elemento de tipo EPersona a la lista seg�n ingreso del usuario.
  * \param lista a la que se agregar� el elemento.
  * \param tama�o del array
  */

void agregarPersona(EPersona[]);

/** \brief valida que el n�mero se encuentre en el rango ingresado. Si se pasa maximo o minimo invertidos, imprime error.
 * \param n�mero a validar dentro de un rango
 * \param n�mero m�ximo inclusive
 * \param n�mero m�nimo inclusive
 * \return 1 si est� dentro del rango, o 0 si no lo est�.
 */

int validarRango(int, int, int);

/** \brief valida que el nombre pasado como par�metro no supere un l�mite determinado
 * \param nombre que se pasa como parametro
 * \param l�mite de caracteres
 * \return 1 si es v�lido, o 0 si no es v�lido
 */

int validarNombre(char[], int);

/** \brief Busca un elemento de la lista de personas seg�n dni, y la oculta.
 *  \      Los campos de estado del tipo EPersona cuyo valor es 2, son ignorados para mostrar.
 * \param lista de elementos tipo persona
 * \return el indice de la persona encontrada, o -1 si no encontr� candidato.
 */

int borrarPersona(EPersona[]);

/** \brief Muestra los elementos de una lista de tipo EPersona, cuyo campo de estado tenga el valor de 1.
 * \param lista de tipo persona a mostrar
 * \param tama�o de la lista
 */

void mostrarPersonas(EPersona[], int);

/** \brief Ordena elementos de la lista tipo EPersona seg�n el campo 'nombre'. El orden es de menor a mayor alfab�tico.
 * \param lista de elementos tipo persona a ordenar
 * \param tama�o de la lista
 */

void ordenarPersNombre(EPersona[], int);

/** \brief muestra al usuario la cantidad de personas seg�n rango de edad. La clasificaci�n de edad est� dividida
 *  \ en 3 categor�as: menores a 18, entre 18 y 35, y mayores a 35. Se denota un asterisco para cada persona.
 * \param lista de elementos tipo EPersona a mostrar
 * \param tama�o de la lista
 */

void mostrarPersEdad(EPersona[], int);

#endif // FUNCIONES_H_INCLUDED
