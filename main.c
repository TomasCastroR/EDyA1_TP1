#include "generar.h"
#include "glist.h"
#include "sorting.h"
#include "persona.h"
#include <locale.h>

int main (int argc, char *argumentos[]) {
  assert (argc == 5);
  setlocale(LC_ALL, "");

  int cantidad = atoi (argumentos[3]);
  crear_archivo_personas (cantidad, argumentos[1], argumentos[2], argumentos[4]);
  GList *lista = crear_lista_personas (argumentos[4], cantidad);

  ordenar_escribir_lista ("personasInsertionEdad.txt", lista, &glist_insertion_sort, &menor_edad);
  ordenar_escribir_lista ("personasInsertionNombre.txt", lista, &glist_insertion_sort, &ordena_nombre);

  ordenar_escribir_lista ("personasSelectionEdad.txt", lista, &glist_selection_sort, &menor_edad);
  ordenar_escribir_lista ("personasSelectionNombre.txt", lista, &glist_selection_sort, &ordena_nombre);

  ordenar_escribir_lista ("personasMergeEdad.txt", lista, &glist_merge_sort, &menor_edad);
  ordenar_escribir_lista ("personasMergeNombre.txt", lista, &glist_merge_sort, &ordena_nombre);

  glist_destruir (lista, &liberar_persona);
  return 0;
}
