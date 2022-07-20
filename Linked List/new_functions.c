#include "LinkedList.h"

void init_list(linkedList **list) { *list = (linkedList *)malloc(sizeof(linkedList)); head((*list)) = NULL; length((*list)) = 0; }

listNode *search(linkedList *list, void *target) {
    if ( head(list) == NULL ) { printf("empty list\n"); return NULL; }
    if ( (head(list)->data).id == target ) { return head(list); }

    listNode *curr = head(list);
    do {  // searching
        if ( cmpkey(*(data(curr)), *target) == 0 ) { return curr; }
        else { curr = link(curr); }
    } while ( curr != NULL );
    return NULL;
}  // search(): serach sequently

extern inline int insert(linkedList *list, listNode *prev, void *data) {
    if ( prev != NULL ) {  // inserted behind of prev
        listNode *new = (listNode *)malloc(sizeof(listNode));
        data(new) = data;
        length(list)++;
        return 1;
    } // if

    listNode *new = (listNode *)malloc(sizeof(listNode));
    if ( head(list) == NULL ) {  // first insertion
        data(new) = data;
        length(list)++;
        return 1;
    } // if

    if ( search(list, data) == NULL ) {  // insert to tail 
        data(new) = data;
        tail(list)->link = new; tail(list) = new;
        length(list)++;
        return 1;
    } // if
    else {
        return -1;
    } // else
} // insert(): insert the node

int delete(linkedList *list, void *target) {
    
}
