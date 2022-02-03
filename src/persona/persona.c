#include "persona.h"
#include <string.h>
#include <time.h>

Persona* crear_persona (char* nombre, int edad, char* localidad) {
  Persona* nuevaPersona = malloc (sizeof(Persona));
  assert(nuevaPersona);
  nuevaPersona->nombre = malloc (sizeof(char) * (strlen (nombre) + 1));
  assert(nuevaPersona->nombre);
  strcpy (nuevaPersona->nombre, nombre);
  nuevaPersona->nombre[strlen (nombre)] = '\0';
  nuevaPersona->edad = edad;
  nuevaPersona->localidad = malloc (sizeof(char) * (strlen (localidad) + 1));
  assert(nuevaPersona->localidad);
  strcpy (nuevaPersona->localidad, localidad);
  nuevaPersona->localidad[strlen (localidad)] = '\0';
  return nuevaPersona;
}

GList* crear_lista_personas (char* nombreArchivo, int cantidadPersonas) {
  char nombre[100], localidad[100];
  int edad;
  GList *lista = glist_crear();
  Persona* persona;
  FILE* archivoPersonas = fopen (nombreArchivo, "r");
  for(int i = 0; i < cantidadPersonas; ++i) {
    fscanf (archivoPersonas,"%[^,], %d, %[^\n]\n", nombre, &edad, localidad);
    persona = crear_persona (nombre, edad, localidad);
    glist_agregar_final (&lista, persona);
  }
  fclose (archivoPersonas);
  return lista;
}

void ordenar_escribir_lista (char* nombreSalida, GList *lista,
                                     FuncionOrdenar ordena, Comparar compare) {
  GList *listaAOrdenar = glist_copiar (lista);
  clock_t tiempoInicial,tiempoFinal;
  tiempoInicial = clock();
  listaAOrdenar = ordena (listaAOrdenar, compare);
  tiempoFinal = clock();
  double segundos = (double)(tiempoFinal - tiempoInicial)/CLOCKS_PER_SEC;
  Persona *persona;
  FILE* archivoSalida = fopen (nombreSalida, "w");
  for (GNodo *temp = listaAOrdenar->primero; temp != NULL; temp = temp->sig) {
    persona = (Persona*)temp->dato;
    fprintf (archivoSalida, "%s, %d, %s\n", persona->nombre, persona->edad, persona->localidad);
  }
  fprintf (archivoSalida, "\nTiempo de ejecucion del algoritmo: %.3lf segundos\n", segundos);
  fclose (archivoSalida);
  glist_destruir (listaAOrdenar, &liberar_nodo);
}

void liberar_persona (void *nodoALiberar) {
  GNodo *nodoAux = (GNodo*)nodoALiberar;
  Persona *personaAux = (Persona*)nodoAux->dato;
  free (personaAux->nombre);
  free (personaAux->localidad);
  free (nodoAux->dato);
  free (nodoALiberar);
}

int menor_edad (void *dato1, void *dato2) {
  Persona *persona1 = (Persona*)dato1;
  Persona *persona2 = (Persona*)dato2;
  return persona1->edad < persona2->edad;
}

int ordena_nombre (void *dato1, void *dato2) {
  Persona *persona1 = (Persona*)dato1;
  Persona *persona2 = (Persona*)dato2;
  return strcmp (persona2->nombre,persona1->nombre);
}
