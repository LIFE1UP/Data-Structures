#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void *data;
    struct Node *left, *right;
} node;

typedef struct Tree {
    int size;
    int (*compare)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    node *root;
} tree;

#define key(node) node->key
#define data(node) node->data
#define left(node) node->left
#define right(node) node->right
#define root(tree) tree->root
#define size(tree) tree->size

void tree_init(tree *target, void (*destroy_fn)(void *data));
void tree_destory(tree *target);
int tree_ins_left(tree *target, node *parent, const void *data);
int tree_ins_right(tree *target, node *parent, const void *data);
void tree_rem_left(tree *target, node *parent);
void tree_rem_right(tree *target, node *parent);

#endif
