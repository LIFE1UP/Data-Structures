#include "BST.h"

void tree_init(tree *target, void (*destroy_fn)(void *data)) { target->size = 0; target->destroy = destroy_fn; target->root = NULL; return; }

void tree_destory(tree *target) { tree_rem_left(target, NULL); memset(target, 0, sizeof(tree)); return; }

extern inline int tree_ins_left(tree *target, node *parent, const void *content) {
    node *new, **position;

    if ( parent == NULL ) {  // empty root
        if (size(target) > 0) { printf("someting is wrong\n"); return -1; }
        position = &(target->root); }

    if ( left(parent) != NULL ) { return -1; }

    position = &parent->left;
    if ( ( new = (node *)malloc(sizeof(node)) ) == NULL ) {
        (new->data) = (void *)content; (target->size)++;
        new->left = NULL; new->right = NULL;
        *position = new;
        return 0;
    }  // insertion

    return -1;
}  // tree_ins_left(): return 0 when successes otherwise -1

extern inline int tree_ins_right(tree *target, node *parent, const void *content) {
    node *new, **position;

    if ( parent == NULL ) {
        if ( size(target) > 0 ) { printf("something is wrong\n"); return -1; }
        position = &(target->root);
    } // first insertion
    
    if ( right(parent) != NULL ) { return -1; }  // already exsit

    position = &parent->right;
    if ( ( new = (node *)malloc(sizeof(node)) ) == NULL ) {
        new->data = (void *)content; (target->size)++;
        new->left = NULL; new->right = NULL;
        *position = new;
        return 0;
    } // insertion

    return -1;
}  // tree_ins_right(): return 0 when successes otherwise -1

extern inline void tree_rem_left(tree *target, node *parent) {
    if ( size(target) == 0 ) { return; }

    node **position;

    if ( parent == NULL ) { position = &(target->root); }
    else { position = &(parent->left); }

    /* important */
    if ( *position != NULL ) {
        tree_rem_left(target, *position); tree_rem_right(target, *position);

        if ( target->destroy != NULL ) { target->destroy( (*position)->data ); }  // when destroy is not defined

        free(*position); *position = NULL;
        (target->size)--;
    }  // left is not empty

    return;
}  // tree_rem_left(): destroy every child of left

extern inline void tree_rem_right(tree *target, node *parent) {
    if ( size(target) == 0 ) { return; }

    node **position;

    if ( parent == NULL ) { position = &(target->root); }
    else { position = &(parent->right); }

    /* important */
    if ( *position != NULL ) {
        tree_rem_left(target, *position); tree_rem_right(target, *position);

        if ( target->destroy != NULL ) { target->destroy( (*position)->data ); }  // when destroy is not defined

        free(*position); *position = NULL;
        (target->size)--;
    }  // right is not empty

    return;
}  // tree_rem_left(): destroy every child of right
