#include "BST.h"

int bin_search(node **curr, int key, int cnt, node **found) {
    // found: cnt, end: 0, error: -1
    if (*curr == NULL) {
        return -1;
    }
    
    if ((*curr)->key == key) {
        return cnt;
    }
    
    if ((*curr)->key < key) {
        if ((*curr)->right == NULL) {
            *found = *curr; return 0;
        }
        
        return bin_search((*curr)->right, key, cnt + 1, found);
    } else {
        if ((*curr)->left == NULL) {
            *found = *curr; return 0;
        }
        
        return bin_search((*curr)->left, key, cnt + 1, found);
    }
}

int insert(tree **root, int key, void *data, void (*destroy)(void *data)) {
    if ((*root)->head == NULL) {
        node* new_node = (node *)malloc(sizeof(node));
        left(new_node) = NULL; right(new_node) = NULL; destroy(new_node) = destroy; key(new_node) = key; data(new_node) = data;
        tree_head((*root)) = new_node;
        
        return 1;
    }

    int place; node *curr = (*root)->head, *found;
    if ((place = bin_search(&curr, key, 1, &found)) == 0) {
        node* new_node = (node *)malloc(sizeof(node)); left(new_node) = NULL; right(new_node) = NULL; destroy(new_node) = destroy; key(new_node) = key; data(new_node) = data;

        if (found->key < key) {
            right(found) = new_node;
        } else {
            left(found) = new_node;
        }

        return 1;
    }

    return -1;
}

int search(tree **root, int key, void **data_ptr) {
    if ((*root)->head == NULL) {
        printf("\btree is empty\n");
        return -1;
    }

    int place; node *found;
    if ((place = bin_search((*root)->head, key, 1, &found)) > 0) {
        *data_ptr = data(found);

        printf("\bfound at %d\n", place); return place;
    } else {
        printf("\bcouldn't find\n", place); return -1;
    }
}

int delete(tree **root, int key) {
    int place = bin_search((*root)->head, key, 1, &found); node *found;
    if (place == 0) {
        if (found->key < key) {
            free(found->right); right(found) = NULL;
        } else {
            free(found->left); left(found) = NULL;
        }

        printf("%d got deleted", key); return 1;
    }

    node *curr;
    if (place > 0) {
        if (found->key < key) {
            curr = right(found);

            if ((*curr)->left == NULL && (*found)->right != NULL) {
                right(found) = right(curr);
            } else if ((*curr)->left != NULL && (*found)->right == NULL) {
                left(found) = left(curr);
            }
        } else {
            curr = left(found);

            if ((*curr)->left == NULL && (*found)->right != NULL) {
                free(curr->right);
                right(found) = right(curr);
            } else if ((*curr)->left != NULL && (*found)->right == NULL) {
                free(curr->left);
                left(found) = left(curr);
            }
        }
        
    }
}
