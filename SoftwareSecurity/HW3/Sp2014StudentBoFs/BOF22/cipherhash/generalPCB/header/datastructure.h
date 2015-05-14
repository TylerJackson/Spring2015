/*
 * datastructure.h
 *
 *  Created on: Feb 15, 2015
 *      Author: hilberttaylor
 */


#ifndef DATASTRUCTURE_H
#define	DATASTRUCTURE_H

// mainly used for the program counter

struct chainedList_t;

typedef struct chainedList_t
{
    char *nameID;
    struct chainedList_t *next;
    struct chainedList_t *prev;
}chainedList_t ;

typedef struct List_t {
    int count;
    chainedList_t *first;
    chainedList_t *last;
}List_t;

/*
 List primitive
 */
List_t *List_t_create(); //creates the main List struct
void List_t_destroy(List_t *list);//Destroys a List and any elements it might have.
void List_t_clear(List_t *list);//function for freeing the values in each node, not the nodes.
void List_t_clear_destroy(List_t *list);//Clears and destroys a list.

#define List_t_count(A) ((A)->count)
#define List_t_first(A) ((A)->first != NULL ? (A)->first->nameID : NULL)
#define List_t_last(A) ((A)->last != NULL ? (A)->last->nameID : NULL)

void List_t_push(List_t *list, char *nameID);//adds a new element to the end of the list
void *List_t_pop(List_t *list);// takes the last element off and returns it.

void List_t_unshift(List_t *list, char *nameID);//add elements to the front of the list
void *List_t_shift(List_t *list);//removes the first element and returns it

void *List_t_remove(List_t *list, chainedList_t *knot);//removes an knot from the front; the end; both front and end; or middle

//Iterates over the elements in the list
#define LIST_FOREACH(L, S, M, V) chainedList_t *_knot = NULL;\
    chainedList_t *V = NULL;\
    for(V = _knot = L->S; _knot != NULL; V = _knot = _knot->M)

#endif /* DATASTRUCTURE_H */
