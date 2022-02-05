#include "input.h"
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

#define LARGO_BUFFER 1024
#define RANGO_EDAD 100

int cant_lineas (char* nombreArchivo) {
  int lineas = 0;  
  FILE* f = fopen(nombreArchivo, "r");
  if (f == NULL)
    lineas = -1;
  else {
      size_t res = 0;
      char buf[LARGO_BUFFER];
      for(;feof(f);) {
          res = fread (buf, 1, LARGO_BUFFER, f);
          for (int i = 0; i < res; i++) {
              if (buf[i] == '\n' || buf[i] == '\r')
                lineas++;
          }
      }
  }
  fclose(f);
  return lineas;
}

void liberar_arreglo_strings (ArregloStrings *arreglo) {
  for (int i = 0; i < arreglo->capacidad; ++i) {
    free (arreglo->strings[i]);
  }
  free (arreglo->strings);
  free (arreglo);
}

ArregloStrings* crear_arreglo_strings (char *nombreArchivo) {
  char buffer[LARGO_BUFFER];
  int capacidad = cant_lineas (nombreArchivo);
  ArregloStrings *nuevoArreglo = malloc (sizeof(ArregloStrings));
  assert(nuevoArreglo);
  nuevoArreglo->strings = malloc (sizeof(char*) * capacidad);
  assert(nuevoArreglo->strings);
  nuevoArreglo->capacidad = capacidad;
  FILE *archivo = fopen (nombreArchivo, "r");
  for (int i = 0; i < capacidad; ++i) {
    fscanf (archivo, "%[^\n]\n", buffer);
    nuevoArreglo->strings[i] = malloc (sizeof(char) * (strlen(buffer) + 1));
    assert(nuevoArreglo->strings[i]);
    strcpy (nuevoArreglo->strings[i], buffer);
    nuevoArreglo->strings[i][strlen(buffer)] = '\0';
  }
  fclose (archivo);
  return nuevoArreglo;
}

void crear_archivo_personas (int cantPersonas,char *archivoNombres,
                                      char *archivoPaises, char *nombreSalida) { 
  int random1, random2, edad;
  ArregloStrings *arregloNombres = crear_arreglo_strings (archivoNombres);
  ArregloStrings *arregloPaises = crear_arreglo_strings (archivoPaises);
  FILE *archivoSalida = fopen (nombreSalida, "w");
  srand (time(NULL) + getpid());
  for (int i = 0; i < cantPersonas; i++) {
    random1 = rand() % arregloNombres->capacidad;
    random2 = rand() % arregloPaises->capacidad;
    edad = (rand() % RANGO_EDAD) + 1;
    fprintf (archivoSalida, "%s, %d, %s\n", arregloNombres->strings[random1],
                                         edad, arregloPaises->strings[random2]);
  }
  fclose (archivoSalida);
  liberar_arreglo_strings (arregloNombres);
  liberar_arreglo_strings (arregloPaises);
}

