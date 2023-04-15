#include "cola.h"
#include "lista.h"

//Pre: -
//Post: Devuelve true si la cola tiene cero elementos o no existe.
bool cola_vacia(cola_t *cola)
{
	if (!cola)
		return NULL;

	return (cola_t*)lista_vacia((lista_t*)cola);
}

//Pre: -
//Post: -
cola_t *cola_crear()
{
	return (cola_t*)lista_crear();
}

//Pre: -
//Post: Agrega un elemento al final de la cola.
cola_t *cola_encolar(cola_t *cola, void *elemento)
{
	if (!cola || !elemento)
		return NULL;

	return (cola_t*)lista_insertar((lista_t*)cola, elemento);
}

//Pre: -
//Post: Quita un elemento del principio de la cola.
void *cola_desencolar(cola_t *cola)
{
	if (!cola)
		return NULL;

	return (cola_t*)lista_quitar_de_posicion((lista_t*)cola, 0);
}

//Pre: -
//Post: -
void *cola_frente(cola_t *cola)
{
	if (!cola)
		return NULL;

	return (cola_t*)lista_primero((lista_t*)cola);
}

//Pre: -
//Post: Devuelve la cantidad de elementos en la cola.
size_t cola_tamanio(cola_t *cola)
{
	if (!cola)
		return 0;

	return (size_t)(cola_t*)lista_tamanio((lista_t*)cola);
}

//Pre: -
//Post: Destruye todos los elementos almacenados en la cola.
void cola_destruir(cola_t *cola)
{
	lista_destruir((lista_t*)cola);
}
