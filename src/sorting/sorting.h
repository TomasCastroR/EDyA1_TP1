#ifndef __SORTING_H__
#define __SORTING_H__

#include "glist.h"

typedef int (*Comparar) (void *dato1, void *dato2);

/*glist_insertion_sort: GList*, Comparar -> GList*
  Recibe una lista del tipo GList* y una funcion de tipo Comparar.
    Retorna una lista ordenada utilizando el metodo de insertion sort */
GList* glist_insertion_sort (GList *lista, Comparar compare);

/*glist_selection_sort: GList*, Comparar -> GList*
  Recibe una lista del tipo GList* y una funcion de tipo Comparar.
    Retorna una lista ordenada utilizando el metodo de selection sort */
GList* glist_selection_sort (GList *lista, Comparar compare);

/* glist_merge_sort: GList*, Comparar -> GList*
  Recibe una lista del tipo GList y una funcion de tipo Comparar.
    Mediante recursividad va diviediendo la lista a la mitad hasta que quedan
  de 1 elemento y las ordena aplicando la funcion merge.*/
GList* glist_merge_sort (GList *lista, Comparar compare);

/*merge: GList*, GList*, Comparar -> GList*
  Recibe dos listas del tipo GList* y una funcion de tipo Comparar.
    Retorna una lista ordenada mergeando las dos listas */
GList* glist_merge (GList *lista1, GList *lista2, Comparar compare);

/*swap_dato: void**, void**
  Recibe 2 datos del tipo void** e intercambia sus valores.*/
void swap_dato (void **dato1, void **dato2);

#endif