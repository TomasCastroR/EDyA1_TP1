#ifndef __PERSONA_H__
#define __PERSONA_H__

#include "glist.h"
#include "sorting.h"

typedef struct {
  char* nombre;
  int edad;
  char* localidad;
}Persona;

typedef GList* (*FuncionOrdenar) (GList *lista, Comparar compare);

/* crear_persona: char*, int, char* -> Persona 
  Recibe un nombre, edad y localidad.
    Retorna una estructura del tipo Persona con esos datos. */
Persona* crear_persona (char* nombre, int edad, char* localidad);

/* crear_lista_personas: char*, int -> GList
  Recibe el nombre del archivo de personas, y la cantidad de personas.
    Retorna una lista de personas. */
GList* crear_lista_personas (char* nombrearchivo, int cantidadpersonas);

/* ordenar_escribir_lista: char*, GList, FuncionOrdenar, Comparar
    Recibe el nombre del archivo de salida, una lista, una funcion ordena del tipo 
  funcionOrdenar y una funcion compare del tipo Comparar.
    Escribe sobre un archivo la lista ordenada, calcula el tiempo
  tardado y la libera cuando termina. */
void ordenar_escribir_lista (char* nombreSalida, GList *lista,
                                       FuncionOrdenar ordena, Comparar compare);
/* liberar_persona: void*
  Recibe un dato del tipo void*, libera todos los elementos que contiene y el nodo.*/
void liberar_persona (void *nodoALiberar);

/* menor_edad: void*, void* ->int
  Toma 2 datos del tipo void*, castea los datos a Persona, compara sus edades y
  devuelve 1 si el primero es menor, 0 si son iguales o si el segundo es menor. */
int menor_edad (void *dato1, void *dato2);

/* ordena_nombre: void*, void* ->int
  Toma 2 datos del tipo void*,castea los datos a Persona, compara sus nombres y
  devuelve 1 si el primero es menor, 0 si son iguales o -1 si el segundo es menor.*/
int ordena_nombre (void *dato1, void *dato2);

#endif