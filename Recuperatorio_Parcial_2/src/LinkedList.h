#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utn.h"

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


struct Node {
	void* element;
	struct Node* nextNode;
} typedef Node;

struct LinkedList {
	Node* firstNode;
	int size;
} typedef LinkedList;

LinkedList* ll_new(void);
int ll_lenght(LinkedList* this);
int ll_add(LinkedList* this, void* element);
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index, void* element);
int ll_remove(LinkedList* this, int index);
int ll_clear(LinkedList* this);
int ll_delete(LinkedList* this);
int ll_indexOf(LinkedList* this, void* element);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* element);
void* ll_pop(LinkedList* this, int index);
int ll_contains(LinkedList* this, void* element);
int ll_containsAll(LinkedList* this1, LinkedList* this2);
LinkedList* ll_subList(LinkedList* this, int from, int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*function)(void*, void*), int order);
int ll_count(LinkedList* this, int (*function)(void*));
LinkedList* ll_filter(LinkedList* this, void (*function)(void*));

#endif /* LINKEDLIST_H_ */
