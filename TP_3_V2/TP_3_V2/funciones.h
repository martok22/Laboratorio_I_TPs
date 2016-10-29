#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int id;
    int estado; // 0 vacío, 1 ocupado, 2 borrado
}eMovie;

/**
 *  Agrega una pelicula a la lista de peliculas pasada como parametro
 *  @param lista de estructuras movies donde se agregara una pelicula
 *  @param tamaño de la lista
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie[], int);

/**
 *  Borra una pelicula a la lista de peliculas pasada como parametro
 *  @param lista de estructuras movies donde se seleccionara una pelicula a borrar
 *  @param tamaño de la lista
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int bajaPelicula(eMovie[], int);

/**
 *  Genera un archivo html a partir de las peliculas cargadas.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 *  @param tamaño de la lista de peliculas
 */
void generarPagina(eMovie[], char[], int);

void leerArchivo(eMovie peliculas[], int tam, char[]);

void guardarArchivo(eMovie peliculas[], int tam, char nombre[]);

int validarCadena (char cadena[], int num);

/** \brief Inicializa el campo de estado de un array de estructuras en el valor de 1.
 * \param Array de un tipo de estructura
 * \param Tamaño del array
 */
void inicializarPeliculas(eMovie[], int);

/** \brief Imprime lista de peliculas, y guarda opcion elegida por el usuario.
 * \param Lista de estructuras de peliculas
 * \param Tamaño del array
 * \return Opcion elegida por el usuario.
 */
int menuPeliculas(eMovie[], int);

/** \brief Busca el indice del primer elemento del array pasado como parametro,
 *  \brief cuyo campo coincide con el entero ingresado
 * \param Array de estructura donde se busca el elemento
 * \param Tamaño del array
 * \return -1 si no encontro, o el índice del primer elemento.
 */
int buscarPelicula (eMovie[], int, int);

/** \brief Busca un elemento de un array de estructura con campo de estado en valor 0.
 * \param Array de estructura
 * \param Tamaño del array
 * \return -1 si no encontró, o el índice del primer elemento.
 */
int espacioLibrePelicula(eMovie[], int);

/** \brief Valida que un numero entero sea positivo o 0.
 * \param Numero a validar
 * \return 1 Si esta validado, 0 si no es valido.
 */
int validarPositivoEntero(int);

/** \brief Valida que la cadena pasada como parámetro sea menor al numero pasado como parámetro, y mayor a 0.
 * \param Cadena a validar
 * \param Tamaño como maximo
 * \return 1 si es correcto, 0 si no cumple la condicion.
 */
int validarCadena(char[], int);

/** \brief Valida que un numero entero se encuentre dentro de un rango (inclusive los bordes).
 *  \brief Invierte max y minimo si son ingresados al revez
 * \param Numero a validar
 * \param Maximo
 * \param Minimo
 * \return 1 Si esta validado, 0 si no es valido.
 *
 */
int validarRangoEntero  (int, int, int);



#endif // FUNCIONES_H_INCLUDED
