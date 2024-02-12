#include <stdlib.h>
#include <string.h>
#include "node.h"

node *insert_node(node *front, char* id, double x, double y) {
    char *tree_name = malloc(sizeof(char) * (strlen(id)+1));
    tree_name = strcpy(tree_name, id);
    node *head = malloc(sizeof(node));
    if (head == NULL) {
        return NULL;
    }

    head->id = tree_name;
    head->xcoord = x;
    head->ycoord = y;
    head->next = front;

    return head;
}