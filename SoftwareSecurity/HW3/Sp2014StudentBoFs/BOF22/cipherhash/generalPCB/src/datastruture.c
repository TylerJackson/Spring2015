/*
 * datastruture.c
 *
 *  Created on: Feb 15, 2015
 *      Author: hilberttaylor
 */

#include <malloc.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "bughandler.h"
#include "datastructure.h"



List_t *List_t_create()
{
    return (List_t *)malloc(sizeof(List_t));
}

void List_t_destroy(List_t *list)
{
    LIST_FOREACH(list, first, next, cur) {
        if(cur->prev) {
            free(cur->prev);
        }
    }

    free(list->last);
    free(list);
}


void List_t_clear(List_t *list)
{
    LIST_FOREACH(list, first, next, cur) {
        free(cur->nameID);
    }
}

void List_t_clear_destroy(List_t *list)
{
    List_t_clear(list);
    List_t_destroy(list);
}

void List_t_push(List_t *list, char *nameID)
{
    chainedList_t *knot = malloc(sizeof(chainedList_t));
    check_mem(knot);
        knot->nameID = nameID;

        if(list->last == NULL) {
            list->first = knot;
            list->last = knot;
        } else {
            list->last->next = knot;
            knot->prev = list->last;
            list->last = knot;
        }

        list->count++;
error:
    return;
}

void *List_t_pop(List_t *list)
{
    chainedList_t *knot = list->last;
    return knot != NULL ? List_t_remove(list, knot) : NULL;
}

void List_t_unshift(List_t *list, char *nameID)
{
    chainedList_t *knot = malloc(sizeof(chainedList_t));
    check_mem(knot);
        knot->nameID = nameID;

        if(list->first == NULL) {
            list->first = knot;
            list->last = knot;
        } else {
            knot->next = list->first;
            list->first->prev = knot;
            list->first = knot;
        }

        list->count++;

error:
    return;
}

void *List_t_shift(List_t *list)
{
    chainedList_t *knot = list->first;
    return knot != NULL ? List_t_remove(list, knot) : NULL;
}

void *List_t_remove(List_t *list, chainedList_t *knot)
{
    void *result = NULL;

    check(list->first && list->last, "List_t is empty.");
    check(knot, "knot can't be NULL");

    if(knot == list->first && knot == list->last) {
        list->first = NULL;
        list->last = NULL;
    } else if(knot == list->first) {
        list->first->next = knot->next;
        check(list->first != NULL, "Invalid list, somehow got a first that is NULL.");
        list->first->prev = NULL;
    } else if (knot == list->last) {
        list->last->prev = knot->prev;
        check(list->last != NULL, "Invalid list, somehow got a next that is NULL.");
        list->last->next = NULL;
    } else {
        chainedList_t *after = knot->next;
        chainedList_t *before = knot->prev;
        after->prev = before;
        before->next = after;
    }

    list->count--;
    result = knot->nameID;
    free(knot);

error:
    return result;
}

