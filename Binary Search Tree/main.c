#include "BST.h"

// custom functions: you can't make your own funntion for your data struutre


int main() {
    tree *root = (tree *)malloc(sizeof(tree)); root->head = NULL; root->name = 'a';

    FILE *inpt_key = fopen("key.txt", "r"); char buffer_key[READ_LENGTH];;

    int count = 0;  void (*destroy)(void *data) = destroy;
    while (fgets(buffer_key, READ_LENGTH, inpt_key) != NULL) {
        buffer_key[strcspn(buffer_key, "\n")] = 0;
        insert(&root, atoi(buffer_key), NULL, NULL);

        count++;
    }
    printf("%d elements added\n\n" , count); fclose(inpt_key);


    int result, line = 0; void *value;
    printf("if you want to exit, type -1\n");
    while (1) {
        printf("search for: "); scanf("%d", &line);
        if (line == -1) {
            printf("\bexiting..,\n"); return 0;
        }
        
        void *value;
        search(&root, line, &value);
    }

    printf("unknown exiting..,\n"); return 0;
}
