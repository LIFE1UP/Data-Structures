#include "linkedList.h"

const int MAX_READ = 1000, STR_LENGTH = 100;

int command(char context[STR_LENGTH]) {
    if (strcmp(context, "exit") == 0) {return 0;}
    if (strcmp(context, "print") == 0) {return 1;}
    if (strcmp(context, "search") == 0) {return 2;}
    if (strcmp(context, "insert") == 0) {return 3;}
    if (strcmp(context, "delete") == 0) {return 4;}
    if (strcmp(context, "getLength") == 0) {return 5;}
    if (strcmp(context, "reverse") == 0) {return 6;}

    return -1;  // type error
}

int main(int argc, char argv[]) {
    // initiate list and insert input
    linkedList *list; initList(&list);
    FILE *inpt = fopen("input.txt", "r");

    char buffer[STR_LENGTH], *token; listData *dummy = (listData *)malloc(sizeof(listData));
    while (fgets(buffer, STR_LENGTH, inpt) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
        token = strtok(buffer, " "); strcpy(dummy->name, token);
        token = strtok(NULL, " "); dummy->id = atoi(token);

        insert(list, NULL, dummy);
    }
    fclose(inpt);

    //  interface
    printf("running LinkedList by LIFE1UP\n");

    int respnse; char *context, *id, *prev_id, *name; listData *data; listNode *found;
    while (1) {
        printf("cmd> "); fgets(buffer, STR_LENGTH, stdin);
        if (strcmp(buffer, "\n") == 0) {continue;}
        buffer[strcspn(buffer, "\n")] = 0;

        context = strtok(buffer, " ");
        switch (respnse = command(context)) {
        case 0:  // exit
            printf("exiting...\n"); return 1;

        case 1:  // print
            printList(list); break;

        case 2:  // search
            id = strtok(NULL, " ");

            if ((found = search(list, atoi(id))) != NULL) {
                data = &(data(found));
                printf("search succeeded...\n%s(%d)\n", data->name, data->id);
            } else {printf("search failed...\n");}

            break;

        case 3:  // insert
            prev_id = strtok(NULL, ", "); id = strtok(NULL, ", "); name = strtok(NULL, " ");

            if ((found = search(list, atoi(prev_id))) != NULL) {
                data = (listData *)malloc(sizeof(listData)); id(data) = atoi(id); strcpy(data->name, name);
                insert(list, found, data);

                printf("inserted...\n");
            } else {printf("insertion failed...\n");}

            break;

        case 4:  // delete
            id = strtok(NULL, " ");
            if (delete(list, atoi(id)) > 0) {
                printf("deleted...\n");
            } else {printf("deletion failed...\n");}

            break;

        case 5:  // getLength
            printf("#elements of the list: %d\n", getLength(list)); break;

        case 6:  // reverse
            reverse(list); printf("reverse succeded..\n"); break;

        case -1:
            printf("type erorr!\n"); break;
        }
    }

    context = NULL; id = NULL; prev_id = NULL; name = NULL; free(data); data = NULL; found = NULL;
    printf("error occured\n"); return -1;
}
