#include "BST.h"

// define data type and destroy of it
void destroy(void *target) { int *dummy = (int *)target; free(dummy); }
void print_node(node *target) { int *dummy = (int *)target->data; printf("%d\n", *dummy); }

int main(int argc, char argv[]) {
    tree first; tree_init(&first, destroy);

    /* still filling codes */

    return 0;
} // main(): main function
