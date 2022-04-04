/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef PRODUCT_LIST_H
#define PRODUCT_LIST_H

#include <string.h>
#include "types.h"
#include "bid_stack.h"


#define LNULL NULL
typedef struct{
    tUserId seller;
    tProductId productId;
    tProductCategory productCategory;
    tProductPrice productPrice;
    tBidCounter bidCounter;
    tStack bidstack;
}tItemL;
typedef struct tNode *tPosL;
struct tNode{
    tItemL data;
    tPosL next;
};
typedef tPosL tList;

//Generadoras
void createEmptyList(tList *L);
/*
* createEmptyList(tList) -> tList
* Objetivo: Crea una lista vacía.
* Entrada:
*      tList: Puntero inicial de la lista
* Salida:
*      tList: Lista correctamente creada
* Poscondición: La lista queda inicializada y no contiene elementos.
*/

//Obserbadoras
bool isEmptyList(tList L);
/*
* isEmptyList (tList) → bool
* Objetivo: Comprobar si la lista esta vacía
* Entrada:
*      tList: lista
* Salida:
*      bool: Devuelve verdadero en caso de vacía.
*/
tPosL first(tList L);
/*
* first (tList) → tPosL
* Objetivo: devolver la posición del primer elemento
* Entrada:
*      tList: lista
* Salida:
*      tPosL: Puntero a la primera posición.
* Precondición: La lista no está vacía.
*/
tPosL last(tList L);
/*
 * last (tList) → tPosL
 * Objetivo: devolver la posición del último elemento
 * Entrada:
 *      tList: lista
 * Salida:
 *      tPosL: Puntero a la última posición.
 * Precondición: La lista no está vacía.
 */
tPosL next(tPosL P, tList L);
/*
 * next (tPosL, tList) → tPosL
 * Objetivo: devolver la posición siguiente a la actual
 * Entrada:
 *      tPosL: Posición actual
 *      tList: lista
 * Salida:
 *      tPosL: Posición siguiente a la actual, LNULL si la actual es la última.
 * Precondición: La posición indicada es una posición válida en la lista.
 */
tPosL previous(tPosL P, tList L);
/*
 * previous (tPosL, tList) → tPosL
 * Objetivo: devolver la posición anterior a la actual
 * Entrada:
 *      tPosL: Posición actual
 *      tList: lista
 * Salida:
 *      tPosL: Posición anterior a la actual, LNULL si la actual es la primera.
 * Precondición: La posición indicada es una posición válida en la lista.
 */
tItemL getItem(tPosL P, tList L);
/*
 * getItem (tPosL, tList) → tItemL
 * Objetivo: devolver el item en la posición dada
 * Entrada:
 *      tPosL: Posición dada
 *      tList: lista
 * Salida:
 *      tItemL: Item en la posición dada
 * Precondición: La posición indicada es una posición válida en la lista.
 */
tPosL findItem(tProductId I, tList L);
/*
 * findItem (tProductId, tList) → tPosL
 * Objetivo: devolver el item en la posición dada
 * Entrada:
 *      tProductId: Id del producto
 *      tList: lista
 * Salida:
 *      tPosL: Posición donde el id del producto coincide con la dada, en caso de no encontrarse se devuelve LNULL.
 */

//Modificadoras
bool insertItem(tItemL I, tList *L);
/*
 * insertItem (tItemL, tPosL, tList) → tList, bool
 * Objetivo: devolver el item en la posición dada
 * Entrada:
 *      tItemL: Item a insertar
 *      tPosL: Posición donde insertar
 *      tList: lista en la que insertar
 * Salida:
 *      tList: lista con el nuevo item si se a podido insertar
 *      bool: verdadera en caso de inserción correcta y falso en el contrario
 * Precondición: La posición indicada es una posición válida en la lista o bien nula (LNULL).
 * Poscondición: Las posiciones de los elementos de la lista posteriores a la del elemento insertado pueden haber variado.
 */
void updateItem(tItemL I, tPosL P, tList *L);
/*
 * updateItem (tItemL, tPosL, tList) → tList
 * Objetivo: Actualizar el item en la posición
 * Entrada:
 *      tItemL: Item a actualizar
 *      tPosL: Posición donde actualizar
 *      tList: lista en la que actualizar
 * Salida:
 *      tList: lista con el nuevo item actualizado
 * Precondición: La posición indicada es una posición válida en la lista.
 * Poscondición: El orden de los elementos de la lista no se ve modificado.
 */

//Destructora
void deleteAtPosition(tPosL P, tList *L);
/*
 * deleteAtPosition (tPosL, tList) → tList
 * Objetivo: eliminar el item en la posición
 * Entrada:
 *      tPosL: Posición a eliminar
 *      tList: lista en la que eliminar
 * Salida:
 *      tList: lista con la posición eliminada si es posible
 * Precondición: La posición indicada es una posición válida en la lista.
 * Poscondición: Las posiciones de los elementos de la lista posteriores a la de la posición eliminada pueden haber variado.
 */

#endif
