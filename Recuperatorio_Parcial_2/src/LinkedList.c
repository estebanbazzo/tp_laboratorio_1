#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex, void* element);


/// @brief
///
/// @return
LinkedList* ll_new(void) {
	LinkedList* this = NULL;
	if((this = (LinkedList*)malloc(sizeof(LinkedList))) != NULL) {
		this->firstNode = NULL;
		this->size = 0;
	}
	return this;
}

/// @brief
///
/// @param this
/// @return
int ll_lenght(LinkedList* this) {
	int auxReturn = -1;
	if(this != NULL) {
		auxReturn = this->size;
	}
	return auxReturn;
}

/// @brief
///
/// @param this
/// @param nodeIndex
/// @return
static Node* getNode(LinkedList* this, int nodeIndex) {
	Node* pN = NULL;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_lenght(this)) {
		pN = this->firstNode;
		for(int i = 0; i < nodeIndex; i++) {
			pN = pN->nextNode;
		}
	}
	return pN;
}

/// @brief
///
/// @param this
/// @param nodeIndex
/// @param element
/// @return
static int addNode(LinkedList* this, int nodeIndex, void* element) {
	int auxReturn = -1;
	Node* pN = NULL;
	Node* auxPN = NULL;
	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_lenght(this)) {
		if((pN = (Node*)malloc(sizeof(Node))) != NULL) {
			if(nodeIndex == 0) {
				pN->nextNode = this->firstNode;
				this->firstNode = pN;
			}
			else if((auxPN = getNode(this, nodeIndex -1)) != NULL) {
				pN->nextNode = auxPN->nextNode;
				auxPN->nextNode = pN;
			}
			pN->element = element;
			this->size++;
			auxReturn = 0;
		}
	}
	return auxReturn;
}

/// @brief
///
/// @param this
/// @param element
/// @return
int ll_add(LinkedList* this, void* element) {
	int auxReturn = -1;
	if(this != NULL) {
		if(!addNode(this, ll_lenght(this), element)) {
			auxReturn = 0;
		}
	}
	return auxReturn;
}

/// @brief
///
/// @param this
/// @param index
void* ll_get(LinkedList* this, int index) {
	void* auxReturn = NULL;
	Node* pN = NULL;
	if(this != NULL && index >= 0 && index < ll_lenght(this)) {
		if((pN = getNode(this, index)) != NULL) {
			auxReturn = pN->element;
		}
	}
	return auxReturn;
}

/// @brief
///
/// @param this
/// @param index
/// @param element
/// @return
int ll_set(LinkedList* this, int index, void* element) {
	int auxReturn = -1;
	Node* pN = NULL;
	if(this != NULL && index >= 0 && index < ll_lenght(this)) {
		if((pN = getNode(this, index)) != NULL) {
			pN->element = element;
			auxReturn = 0;
		}
	}
	return auxReturn;
}

/// @brief
///
/// @param this
/// @param index
/// @return
int ll_remove(LinkedList* this, int index) {
	int auxReturn = -1;
	Node* pN1 = NULL;
	Node* pN2 = NULL;
	if(this != NULL && index >= 0 && index < ll_lenght(this)) {
		if((pN1 = getNode(this, index)) != NULL) {
			if(index == 0) {
				this->firstNode = pN1->nextNode;
			}
			else if((pN2 = getNode(this, index -1)) != NULL) {
				pN2->nextNode = pN1->nextNode;
			}
			free(pN1);
			this->size--;
			auxReturn = 0;
		}
	}
	return auxReturn;
}

/// @brief
///
/// @param this
/// @return
int ll_clear(LinkedList* this) {
	int auxReturn = -1;
	int lenght;
	if(this != NULL && ll_lenght(this) > 0) {
		lenght = ll_lenght(this);
		for(int i = 0; i < lenght; i++) {
			ll_remove(this, i);
		}
		auxReturn = 0;
	}
	return auxReturn;
}

/// @brief
///
/// @param this
/// @return
int ll_delete(LinkedList* this) {
	int auxReturn = -1;
	if(this != NULL) {
		ll_clear(this);
		free(this);
		auxReturn = 0;
	}
	return auxReturn;
}

/// @brief
///
/// @param this
/// @param element
/// @return
int ll_indexOf(LinkedList* this, void* element) {
	int auxReturn = -1;
	int lenght;
	if(this != NULL) {
		lenght = ll_lenght(this);
		for(int i = 0; i < lenght; i++) {
			if(ll_get(this, i) == element) {
				auxReturn = i;
				break;
			}
		}
	}
	return auxReturn;
}

/// @brief
///
/// @param this
/// @return
int ll_isEmpty(LinkedList* this) {
	int auxReturn = -1;
	if(this != NULL) {
		if(ll_lenght(this) > 0) {
			auxReturn = FALSE;
		}
		else {
			auxReturn = TRUE;
		}
	}
	return auxReturn;
}

/// @brief
///
/// @param this
/// @param index
/// @param element
/// @return
int ll_push(LinkedList* this, int index, void* element) {
	int auxReturn = -1;
	if(this != NULL && index >= 0 && index <= ll_lenght(this)) {
		if(!addNode(this, index, element)) {
			auxReturn = 0;
		}
	}
	return auxReturn;
}

/// @brief
///
/// @param this
/// @param index
void* ll_pop(LinkedList* this, int index) {
	void* auxReturn = NULL;
	if(this != NULL && index >= 0 && index < ll_lenght(this)) {
		auxReturn = ll_get(this, index);
		ll_remove(this, index);
	}
	return auxReturn;
}

/// @brief
///
/// @param this
/// @param element
/// @return
int ll_contains(LinkedList* this, void* element) {
	int auxReturn = -1;
	if(this != NULL) {
		if(ll_indexOf(this, element) != -1) {
			auxReturn = TRUE;
		}
		else {
			auxReturn = FALSE;
		}
	}
	return auxReturn;
}

/// @brief
///
/// @param this1
/// @param this2
/// @return
int ll_containsAll(LinkedList* this1, LinkedList* this2) {
	int auxReturn = -1;
	int lenght;
	if(this1 != NULL && this2 != NULL) {
		auxReturn = TRUE;
		lenght = ll_lenght(this2);
		for(int i = 0; i < lenght; i++) {
			if(!ll_contains(this1, ll_get(this2, i))) {
				auxReturn = FALSE;
				break;
			}
		}
	}
	return auxReturn;
}

/// @brief
///
/// @param this
/// @param from
/// @param to
/// @return
LinkedList* ll_subList(LinkedList* this, int from, int to) {
	LinkedList* subList = NULL;
	if(this != NULL && from >= 0 && from < ll_lenght(this) && to > from && to <= ll_lenght(this)) {
		if((subList = ll_new()) != NULL) {
			for(int i = 0; i < to; i++) {
				ll_add(subList, ll_get(this, i));
			}
		}
	}
	return subList;
}

/// @brief
///
/// @param this
/// @return
LinkedList* ll_clone(LinkedList* this) {
	LinkedList* cloneList = NULL;
	if(this != NULL) {
		cloneList = ll_subList(this, 0, ll_lenght(this));
	}
	return cloneList;
}

/// @brief
///
/// @param this
/// @param pFunc
/// @param order
/// @return
int ll_sort(LinkedList* this, int (*function)(void*, void*), int order) {
	int auxReturn = -1;
	int lenght;
	int isOrdered;
	void* element1 = NULL;
	void* element2 = NULL;
	if(this != NULL && function != NULL && (order == 0 || order == 1)) {
		lenght = ll_lenght(this);
		do {
			isOrdered = TRUE;
			lenght--;
			for(int i = 0; i < lenght; i++) {
				if((element1 = ll_get(this, i)) != NULL && (element2 = ll_get(this, i +1)) != NULL) {
					if((order == 1 && function(element1, element2) > 0) || (order == 0 && function(element1, element2) < 0)) {
						ll_set(this, i, element2);
						ll_set(this, i +1, element1);
						isOrdered = FALSE;
					}
				}
			}
		} while(isOrdered == FALSE);
		auxReturn = 0;
	}
	return auxReturn;
}

int ll_count(LinkedList* this, int (*function)(void*)) {
	int auxReturn;
	void* element = NULL;
	int lenght;
	int total;
	if(this != NULL && function != NULL) {
		lenght = ll_lenght(this);
		for(int i = 0; i < lenght; i++) {
			element = ll_get(this, i);
			auxReturn = function(element);
			if(auxReturn) {
				total += auxReturn;
			}
		}
	}
	return total;
}

/*
LinkedList* ll_map(LinkedList* this, void (*function)(void*)) {
	void* auxReturn;
	LinkedList* pLL = NULL;
	void* element = NULL;
	int lenght;
	if(this != NULL && function != NULL) {
		if((pLL = ll_new()) != NULL) {
			lenght = ll_lenght(this);
			for(int i = 0; i < lenght; i++) {
				if((element = ll_get(this, i))) {
					if((auxReturn = function(element))) {
						ll_add(pLL, auxReturn);
					}
				}
			}
		}
	}
	return pLL;
}
*/
