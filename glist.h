#ifndef __GLIST_H__
#define __GLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _GNodo {
  void* dato;
  struct _GNodo *sig;
  struct _GNodo *ant;
}GNodo;

typedef struct {
  GNodo* primero;
  GNodo* ultimo;
}GList;

typedef void (*Destruir) (void *dato);

/*glist_crear:->  Glist*
  Crea y retorna una lista vacia.*/
GList* glist_crear ();

/* glist_destruir: Glist*, Destruir
  Recibe una lista y una funcion destruir.
    Libera la lista y los espacios dentro de la misma.*/
void glist_destruir (GList *lista, Destruir funcionDestruir);

/* glist_agregar_final: GList**, void*
  Recibe una lista y un dato del tipo void*.
    Agrega este dato al final de la lista como ultimo elemento. */
void glist_agregar_final (GList **lista, void *dato);

/* glist_agregar_nodo_final: GList**, GNodo*
  Recibe una lista del tipo GList** y un nodo del tipo GNodo*.
    Agrega el nodo al final de la lista. */
void glist_agregar_nodo_final (GList **lista, GNodo *nodo); 

/* glist_split: GList*, GList**, GList**
  Recibe una lista del tipo GList* y dos listas del tipo GList**.
    Divide la lista en dos, asigna la mitad izquierda a la primer GList** y la
  mitad derecha a la otra GList** */
void glist_split (GList *lista, GList **izquierda, GList **derecha);

/*glist_copiar: GList* -> GList*
  Recibe una lista y crea una nueva lista con los mismos datos. */
GList* glist_copiar (GList *lista);

/*liberar_nodo: void*
  Recibe un dato del tipo void* y lo libera. */
void liberar_nodo (void *nodo);

#endif
