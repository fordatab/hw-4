#include <string.h>
#include "node.h"

node *node_lookup(node *front, char *id) {
    while (front != NULL) {
        if (strcmp(front->id, id) == 0) {
            return front;
        } else {
            front = front->next;
        }
    }
	return NULL;
}