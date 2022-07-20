/*LINKED LIST*/
#ifndef linkedList_H
#define linkedList_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Listnode {
    void *data;
    struct Listnode* link;
} listNode;

typedef struct LinkedList {
    listNode *head, *tail;
    int length;
}linkedList;

#define name(data) data->name
#define id(data) data->id
#define data(node) node->data
#define link(node) node->link
#define head(list) list->head
#define length(list) list->length
#define 

int seq_search(listNode *curr, int target, listNode **prev);
void initList(linkedList **list_p);
void printList(linkedList *list);
listNode *search(linkedList *list, int target);
int insert(linkedList *list, listNode *pre, listData *data);
int delete(linkedList *list, int target);
void reverse(linkedList *list);
int getLength(linkedList *list);
