#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READ_LENGTH 200

typedef struct Node {
    int key;
    void *data;
    struct Node *left, *right;
    void (*destroy)(void *data);
} node;

typedef struct Tree {
    node *head;
    char name;
} tree;

#define key(node) node->key
#define data(node) node->data
#define left(node) node->left
#define right(node) node->right
#define destroy(node) node->destroy
#define tree_head(tree) tree->head

int bin_search(node *curr, int key, int cnt, node **found);
int insert(tree **root, int key, void *data, void (*destroy)(void *data));
int search(tree **root, int key, void **data);
