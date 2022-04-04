#include "linkedList.h"

extern inline int seq_search(listNode *curr, int target, listNode **prev) {
    if (curr == NULL) {return -1;}  // not found
    if ((curr->data).id == target) {return 1;}  // found
    *prev = curr;
    return seq_search(curr->link, target, prev);
}  // sequential search, head to tail

void initList(linkedList **list_p) {*list_p = (linkedList *)malloc(sizeof(linkedList)); head((*list_p)) = NULL; length((*list_p)) = 0; return;}

void printList(linkedList *list) {
    if (list->head == NULL) {printf("empty list\n"); return;}

    listNode *curr = head(list);
    while (curr != NULL) {printf("name: %s id: %d\n", (curr->data).name, (curr->data).id); curr = link(curr);}
}  // print every labels

listNode *search(linkedList *list, int target) {
    if (list->head == NULL) {printf("empty list\n"); return NULL;}
    if ((list->head->data).id == target) {return head(list);}

    int error; listNode *prev, *curr = head(list);
    if ((error = seq_search(list->head, target, &prev)) >= 0) {
        return link(prev);  // found
    } else {printf("couln't found the taget\n"); return NULL;}  // not found
}  // process the result of seq_search

int insert(linkedList *list, listNode *pre, listData *data) {
    // custom insert by human
    if (pre != NULL) {
        listNode *new = (listNode *)malloc(sizeof(listNode)); data(new) = *data;
        link(new) = link(pre); link(pre) = new;
        length(list)++; printf("target got inserted at next of the adderess\n"); return 1;
    }

    // initiation situation
    if (list->head == NULL) {
        head(list) = (listNode *) malloc(sizeof(listNode)); head(list)->data = *data; head(list)->link = NULL;
        length(list)++; printf("target got inserted at head\n"); return 0;
    }

    // not initiation situation
    listNode *prev; int error;
    if ((error = seq_search(list->head, data->id, &prev)) < 0) {
        link(prev) = (listNode *)malloc(sizeof(listNode));
        link(prev)->data = *data; link(prev)->link = NULL;
        length(list)++; printf("target got inserted at end\n"); return 1;
    } else {printf("target already exist!\n"); return -1;}
}

listNode *tmp;
int delete(linkedList *list, int target) {
    // delete head
    if ((list->head->data).id == target) {tmp = head(list); head(list) = link(list->head); free(tmp); length(list)--; return 1;}

    // delete not head
    listNode *prev; int error;
    if ((error = seq_search(list->head, target, &prev)) > 0) {
        tmp = link(prev); link(prev) = link(prev)->link; free(tmp);
        length(list)--; return 1;
    } else {printf("taget do not exist\n"); return -1;}  // target does not exist on the list
}

listNode *temp_curr;
void reverse(linkedList *list) {
    // empty list termination
    if (L->head == NULL) {printf("empty list\n"); return;};

    // reverse the list
    listNode *curr = head(list);
    while (curr->link != NULL) {
        temp_curr = link(curr); link(curr) = link(curr)->link;
        link(temp_curr) = head(list); head(list) = temp_curr;
    }

    printList(list);  // print the list
}

int getLength(linkedList *list) {return length(list);}
