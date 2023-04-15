#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa2m.h"

int comparar_elementos(void *elemento_uno, void *elemento_dos){
	
	if (!elemento_uno || !elemento_dos)
		return -1;

	return strcmp(elemento_uno, elemento_dos);
}

void lista_se_crea_vacia()
{
	lista_t *lista_creada = NULL;
	lista_creada = lista_crear();

	pa2m_afirmar( lista_creada != NULL, "Se puede crear una lista");
	pa2m_afirmar( lista_vacia(lista_creada), "La lista esta vacia");
	pa2m_afirmar( lista_tamanio(lista_creada) == 0, "El tamaño de una lista vacia es cero");
	pa2m_afirmar( lista_creada->nodo_inicio == NULL, "EL primer elemento de una lista vacia es NULL");
	pa2m_afirmar( lista_creada->nodo_inicio == lista_creada->nodo_fin, "El ultimo elemento de una lista vacia es NULL");
	pa2m_afirmar( lista_quitar(lista_creada) == NULL, "Borrar algo de una lista vacia devuelve NULL");
	pa2m_afirmar( lista_quitar_de_posicion(lista_creada, 1) == NULL, "Quitar algo de una posicion con la lista vacia devuelve NULL");

	lista_destruir(lista_creada);
}

void se_insertan_elementos()
{
	lista_t *lista_creada = NULL;
	lista_creada = lista_crear();

	int elemento1 = 10;
	int elemento2 = 20;
	int *elemento_nulo = NULL;

	lista_t *lista = lista_insertar(lista_creada, &elemento1);
	pa2m_afirmar( lista != NULL && *(int*)lista_creada->nodo_inicio->elemento == elemento1 , "Se puede insertar un elemento en la lista");
	pa2m_afirmar( lista_creada->nodo_inicio == lista_creada->nodo_fin, "Al insertar un elemento el nodo inicio y el nodo fin apuntan al mismo lugar");
	pa2m_afirmar( *(int*)lista_ultimo(lista_creada) == elemento1, "El elemento insertado se colocó al final");
	pa2m_afirmar( lista_tamanio(lista_creada) == 1, "Al insertar un elemento, el tamaño de la lista es 1");
	pa2m_afirmar( lista_creada->nodo_fin->siguiente == NULL, "El ultimo elemento apunta a NULL");

	printf("\n");
	
	lista_insertar(lista_creada, &elemento2);
	pa2m_afirmar( lista_tamanio(lista_creada) == 2, "Al insertar otro elemento, el tamaño de la lista es 2");
	pa2m_afirmar( *(int*)lista_ultimo(lista_creada) == elemento2, "El nuevo elemento insertado se colocó al final");
	pa2m_afirmar( *(int*)lista_creada->nodo_inicio->siguiente->elemento == *(int*)lista_creada->nodo_fin->elemento, "Los elemtos en la lista guardan la ubicacion del siguiente");
	pa2m_afirmar( lista_creada->nodo_fin->siguiente == NULL, "El ultimo elemento apunta a NULL");

	lista_insertar(lista_creada, elemento_nulo);
	pa2m_afirmar( lista_creada->nodo_fin->elemento == NULL, "Puedo insertar un elemento nulo");
	lista_destruir(lista_creada);
}

void se_insertan_elementos_en_posiciones()
{

	lista_t *lista_creada = NULL;
	lista_creada = lista_crear();

	int elemento1 = 10;
	int elemento2 = 20;
	int elemento3 = 30;

	lista_insertar_en_posicion( lista_creada, &elemento1, 50);
	pa2m_afirmar( *(int*)lista_creada->nodo_inicio->elemento == elemento1, "Si la lista esta vacia, insertar en posicion inserta al principio");

	lista_insertar(lista_creada, &elemento2); lista_insertar(lista_creada, &elemento3);
	pa2m_afirmar( lista_tamanio(lista_creada) == 3, "Al insertar multiples elementos, la cantidad en la lista es la suma de los mismos");

	int nuevo_elemento = 15;
	lista_insertar_en_posicion(lista_creada, &nuevo_elemento, 1);
	pa2m_afirmar( *(int*)(lista_creada->nodo_inicio->siguiente->elemento) == nuevo_elemento,"Al insertar un elemento en una posicion valida, se inserta en la posicion deseada");
	
	lista_insertar_en_posicion(lista_creada, &nuevo_elemento, 999);
	pa2m_afirmar( *(int*)lista_creada->nodo_fin->elemento == nuevo_elemento, "Al insertar un elemento en una posicion invalida, se inserta al final");

	lista_insertar_en_posicion( lista_creada, &nuevo_elemento, 0);
	pa2m_afirmar( *(int*)lista_creada->nodo_inicio->elemento == nuevo_elemento, "Al insertar un elemento en la posicion 0, este se inserta al principio");

	lista_destruir(lista_creada);
}

void se_quitan_elementos()
{

	lista_t *lista_creada = NULL;
	lista_creada = lista_crear();

	int elemento1 = 10;
	int elemento2 = 20;
	int elemento3 = 30;

	lista_insertar( lista_creada, &elemento1); lista_insertar( lista_creada, &elemento2); lista_insertar( lista_creada, &elemento3);

	pa2m_afirmar( *(int*)lista_quitar(lista_creada) == elemento3, "Los elementos se quitan de la ultima posicion");
	pa2m_afirmar( *(int*)lista_ultimo(lista_creada) == elemento2, "Los elementos se quitan correctamente");
	pa2m_afirmar( lista_tamanio(lista_creada) == 2, "Al quitar elementos, se reduce la cantidad de elementos en la lista");
	pa2m_afirmar( lista_creada->nodo_fin->siguiente == NULL, "El ultimo elemento apunta a NULL");

	lista_destruir(lista_creada);
}

void se_quitan_elementos_en_posiciones()
{
	lista_t *lista_creada = NULL;
	lista_creada = lista_crear();

	int elemento1 = 10;
	int elemento2 = 20;
	int elemento3 = 30;
	int elemento4 = 40;

	lista_insertar( lista_creada, &elemento1); lista_insertar( lista_creada, &elemento2);
	lista_insertar( lista_creada, &elemento3); lista_insertar( lista_creada, &elemento4);

	pa2m_afirmar( *(int*)lista_quitar_de_posicion(lista_creada, 0) == elemento1, "Quitar un elemento del principio funciona correctamente");
	pa2m_afirmar( *(int*)lista_quitar_de_posicion(lista_creada, 999) == elemento4, "Quitar un elemento de una posicion invalida, quita de la ultima posicion");
	pa2m_afirmar( *(int*)lista_quitar_de_posicion(lista_creada, lista_tamanio(lista_creada)) == elemento3, "Quitar un elemento de la ultima posicion funciona correctamente");
	pa2m_afirmar( lista_creada->nodo_fin->siguiente == NULL, "El ultimo elemento siempre apunta a NULL");

	lista_quitar(lista_creada); lista_quitar(lista_creada);

	pa2m_afirmar( lista_creada->nodo_inicio == lista_creada->nodo_fin && lista_creada->nodo_fin == NULL ,"Si la lista queda vacia, el incio y final de la lista son NULL");
	pa2m_afirmar( lista_tamanio(lista_creada) == 0, "Si la lista queda vacia, la cantidad de elementos es 0");

	lista_destruir(lista_creada);
}

void buscar_elementos()
{
	lista_t *lista_creada = NULL;
	lista_creada = lista_crear();

	int elemento1 = 10;
	int elemento2 = 20;

	lista_t *lista_nula = NULL;
	int *elemento_nulo = NULL;

	pa2m_afirmar(lista_buscar_elemento(lista_creada, comparar_elementos, &elemento1) == NULL, "Buscar elementos en una lista vacia devuelve NULL");
	pa2m_afirmar(lista_buscar_elemento(lista_nula, comparar_elementos, &elemento1) == NULL, "Buscar un elemento en una lista que no existe devuelve NULL");
	pa2m_afirmar(lista_buscar_elemento(lista_creada, NULL, &elemento1) == NULL, "Buscar elementos con un comparador que no existe devuelve NULL");

	lista_insertar( lista_creada, &elemento1);
	pa2m_afirmar( *(int*)lista_buscar_elemento(lista_creada, comparar_elementos, &elemento1) == elemento1 , "Si el elemento esta en la lista lo devuelve");
	pa2m_afirmar( lista_buscar_elemento(lista_creada, comparar_elementos, &elemento2) == NULL, "Si el elemento no esta en la lista devuelve NULL");
	pa2m_afirmar( lista_buscar_elemento(lista_creada, comparar_elementos, elemento_nulo) == NULL, "El contexto puede ser NULO");

	lista_destruir(lista_creada);
}

void buscar_posicion()
{
	lista_t *lista_creada = NULL;
	lista_creada = lista_crear();

	int elemento1 = 10;
	int elemento2 = 20;

	pa2m_afirmar( lista_elemento_en_posicion(NULL, lista_tamanio(lista_creada)) == NULL, "Buscar un elemento en una lista que no existe devuelve NULL");
	pa2m_afirmar( lista_elemento_en_posicion(lista_creada, lista_tamanio(lista_creada)) == NULL, "Buscar un elemento en una lista vacia devuelve NULL");

	lista_insertar( lista_creada, &elemento1); lista_insertar( lista_creada, &elemento2);

	pa2m_afirmar( *(int*)lista_elemento_en_posicion(lista_creada, 0 ) == elemento1, "Buscar el primer elemento de la lista devuelve el primero");
	pa2m_afirmar( *(int*)lista_elemento_en_posicion(lista_creada, 1) == elemento2, "Buscar el ultimo elemento de la lista devuelve el ultimo");
	pa2m_afirmar( lista_elemento_en_posicion(lista_creada, 999) == NULL, "Buscar un elemento en una posicion inexistente devuelve NULL");

	lista_destruir(lista_creada);
}

bool recorrer_hasta_final( void *elemento1, void *contexto){
	return true;
}

bool recorrer_inexistentes( void *elemento1, void *contexto){
	if(!elemento1 || !contexto)
		return false;
	return true;
}

bool recorrer_parcialmente( void *elemento1, void *contexto){
	if(*(size_t*)elemento1 == *(size_t*)contexto)
		return false;
	return true;
}

void se_iteran_elementos_internamente()
{
	lista_t *lista_creada = NULL;
	lista_creada = lista_crear();

	int elemento1 = 1, elemento2 = 2, elemento3 = 3;
	lista_insertar( lista_creada, &elemento1); lista_insertar( lista_creada, &elemento2), lista_insertar( lista_creada, &elemento3);

	size_t contexto0 = 0;
	size_t contexto1 = 1;
	size_t contexto2 = 2;
	pa2m_afirmar( lista_con_cada_elemento(lista_creada, recorrer_hasta_final, &contexto0) == 3,"Reccorer todos los elementos devuelve la cantidad de iteraciones correctas");
	pa2m_afirmar( lista_con_cada_elemento(lista_creada, recorrer_inexistentes, NULL) == 0,"Recorrer con un contexto NULO devuelve las iteraciones correctas");
	pa2m_afirmar( lista_con_cada_elemento(lista_creada, recorrer_parcialmente, &contexto1) == 1,"Reccorer hasta la primera posicion funciona correctamente");
	pa2m_afirmar( lista_con_cada_elemento(lista_creada, recorrer_parcialmente, &contexto2) == 2,"Reccorer hasta la posicion dos funciona correctamente");
	pa2m_afirmar( lista_con_cada_elemento(NULL, recorrer_parcialmente, &contexto0) == 0,"Si lista es NULL, devuelve cero");
	pa2m_afirmar( lista_con_cada_elemento(lista_creada, NULL, &contexto0) == 0,"Si la funcion es NULL, devuelve cero");

	lista_destruir(lista_creada);
}

void se_iteran_elementos_externamente()
{
	lista_t *lista_creada = NULL;
	lista_creada = lista_crear();

	int elemento1 = 10, elemento2 = 20;
	lista_insertar( lista_creada, &elemento1); lista_insertar( lista_creada, &elemento2);

	lista_iterador_t *iterador_creado = lista_iterador_crear(lista_creada);
	lista_iterador_t *nulo = lista_iterador_crear(NULL);

	pa2m_afirmar( nulo == NULL, "No puedo crear un iterador con una lista NULL");
	pa2m_afirmar( iterador_creado != NULL, "Puedo crear un iterador");
	pa2m_afirmar( iterador_creado->lista == lista_creada, "La lista del iterador es la correcta");
	pa2m_afirmar( iterador_creado->corriente == lista_creada->nodo_inicio, "La corriente del iterador es la correcta");
	pa2m_afirmar( *(int*)lista_iterador_elemento_actual(iterador_creado) == elemento1, "Iterador_elemento_actual devuelve el elemento en la posicion actual");
	pa2m_afirmar( lista_iterador_tiene_siguiente(iterador_creado) == true, "Iterador_tiene_siguiente devuelve true si PUEDE seguir recorriendose");
	pa2m_afirmar( lista_iterador_avanzar(iterador_creado) == true, "Iterador_tiene_siguiente devuelve true si PUEDE avanzar de posicion");

	lista_destruir(lista_creada);
	lista_iterador_destruir(iterador_creado);
}

void se_prueba_funcionalidad_de_pila()
{
	pila_t *pila_creada = pila_crear();
	
	int elemento1 = 10, elemento2 = 20, elemento3 = 30, elemento4 = 40;

	pa2m_afirmar(pila_creada != NULL, "Puedo crear una pila correctamente");
	pa2m_afirmar(pila_tamanio(pila_creada) == 0,"Al crear la pila, esta tiene cero elementos");
	pa2m_afirmar(pila_desapilar(pila_creada) == NULL, "No puedo quitar elementos de una pila vacia");

	pila_apilar(pila_creada, &elemento1); pila_apilar(pila_creada, &elemento2);
	pila_apilar(pila_creada, &elemento3); pila_apilar(pila_creada, &elemento4);
	pa2m_afirmar(pila_tamanio(pila_creada) == 4,"La cantidad de elementos despues de agregar uno es la correcta");

	pila_desapilar(pila_creada);
	pa2m_afirmar(pila_tamanio(pila_creada) == 3, "La cantidad de elementos luego de quitar uno es la correcta");
	
	pa2m_afirmar( *(size_t*)pila_tope(pila_creada) == elemento3, "El tope de la pila apunta hacia la posicion correcta");

	pila_destruir(pila_creada);
}

void se_prueba_funcionalidad_de_cola()
{
	cola_t *cola_creada = cola_crear();
	
	int elemento1 = 10, elemento2 = 20, elemento3 = 30, elemento4 = 40;

	pa2m_afirmar(cola_creada != NULL, "Puedo crear una cola correctamente");
	pa2m_afirmar(cola_tamanio(cola_creada) == 0,"Al crear la cola, esta tiene cero elementos");
	pa2m_afirmar(cola_desencolar(cola_creada) == NULL, "No puedo quitar elementos de una cola vacia");

	cola_encolar(cola_creada, &elemento1); cola_encolar(cola_creada, &elemento2);
	cola_encolar(cola_creada, &elemento3); cola_encolar(cola_creada, &elemento4);
	pa2m_afirmar(cola_tamanio(cola_creada) == 4,"La cantidad de elementos despues de agregar uno es la correcta");

	cola_desencolar(cola_creada);
	pa2m_afirmar(cola_tamanio(cola_creada) == 3, "La cantidad de elementos luego de quitar uno es la correcta");

	pa2m_afirmar( *(size_t*)cola_frente(cola_creada) == elemento2, "El frente de la cola apunta hacia la posicion correcta");

	cola_destruir(cola_creada);
}

int main()
{

	printf("PRUEBAS DE LISTA:\n");
	pa2m_nuevo_grupo("Pruebas con lista vacia");
	lista_se_crea_vacia();

	pa2m_nuevo_grupo("Pruebas de insercion al final");
	se_insertan_elementos();

	pa2m_nuevo_grupo("Pruebas de insercion en posicion determinada");
	se_insertan_elementos_en_posiciones();

	pa2m_nuevo_grupo("Pruebas de quitar al final");
	se_quitan_elementos();

	pa2m_nuevo_grupo("Pruebas de quitar en posicion determinada");
	se_quitan_elementos_en_posiciones();

	pa2m_nuevo_grupo("Pruebas de lista buscar elementos");
	buscar_elementos();

	pa2m_nuevo_grupo("Pruebas de lista elementos en posicion");
	buscar_posicion();

	pa2m_nuevo_grupo("Pruebas de iterador interno");
	se_iteran_elementos_internamente();

	pa2m_nuevo_grupo("Pruebas de iterador externo");
	se_iteran_elementos_externamente();

	pa2m_nuevo_grupo("Pruebas PILA");
	se_prueba_funcionalidad_de_pila();

	pa2m_nuevo_grupo("Pruebas COLA");
	se_prueba_funcionalidad_de_cola();

	return pa2m_mostrar_reporte();
}
