#include "pila.h"
#include "lista.h"

//Pre: -
//Post: Devuelve true si la cantidad de elementos en la pila es cero o esta vacia.
bool pila_vacia(pila_t *pila)
{
	if (!pila)
		return NULL;

	return lista_vacia((lista_t*)pila);
}

//Pre: -
//Post: -
pila_t *pila_crear()
{
	return (pila_t*)lista_crear();
}

//Pre: -
//Post: Agrega un elemento al principio de la pila.
pila_t *pila_apilar(pila_t *pila, void *elemento)
{
	if (!pila || !elemento)
		return NULL;

	return (pila_t*)lista_insertar_en_posicion((lista_t*)pila, elemento, 0);
}

//Pre: -
//Post: Quita un elemento del principio de la pila.
void *pila_desapilar(pila_t *pila)
{
	return (pila_t*)lista_quitar_de_posicion((lista_t*)pila, 0);
}

//Pre: -
//Post: Indica cual es la posicion del ultimo elemento agregado a la pila.
void *pila_tope(pila_t *pila)
{
	return (pila_t*)lista_primero((lista_t*)pila);
}

//Pre: -
//Post: Devuelve la cantidad de elementos que hay en la pila.
size_t pila_tamanio(pila_t *pila)
{
	if (!pila || pila_vacia(pila))
		return 0;

	return (size_t)(pila_t*)lista_tamanio((lista_t*)pila);
}

//Pre: -
//Post: Destruye todos los elementos almacenados en la pila.
void pila_destruir(pila_t *pila)
{
	lista_destruir((lista_t*)pila);
}