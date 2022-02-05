#ifndef __INPUT_H__
#define __INPUT_H__

#include <stdio.h>

typedef struct {
  char **strings;
  int capacidad;
}ArregloStrings;

/*cantidad_de_lineas: File* -> Int
  Recibe un archivo, devuelve la cantidad de lineas que posee el archivo*/
int cantidad_de_lineas (FILE *archivo);

/*liberar_arreglo_strings: ArregloStrings*
  Recibe una estructura de ArregloStrings,
  y libera los espacios de memoria pedidos */
void liberar_arreglo_strings (ArregloStrings *arreglo);

/* crear_arreglo_strings: char-> ArregloStrings*
  Recibe el nombre del archivo. 
    Devuelve una estructura ArregloStrings, donde cada linea del archivo
  es un string dentro del arreglo. */
ArregloStrings* crear_arreglo_strings (char *nombreArchivo);

/* crear_archivo_personas: int, char*, char*, char*
  Recibe la cantidad de personas, el nombre de archivo de nombres, el nombre de
  archivo de paises y el nombre del archivo de salida.
    Escribe sobre un archivo las personas, con una edad aleatoria que va del 1 al
  100 y una localidad aleatoria del archivo de localidades */
void crear_archivo_personas (int cantPersonas,char *archivoNombre,
                                       char *archivoPaises, char *nombreSalida);

#endif