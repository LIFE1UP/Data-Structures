#ifndef BST_H
#define BST_H

#define LEFT_HEAVY 1
#define BALANCED 0
#define RIGHT_HEAVY -1

typedef struct Node {
    void *data;
    int hidden;
    int factor;
} node;

static void rotate_left(node **target) {
    node *left, *grandchild;

    left = left(*target);
    if ( (node *)data(left)->factor == LEFT_HEAVY ) {
        left(*node) = right(left);
        right(left) = *node;
    }

}
