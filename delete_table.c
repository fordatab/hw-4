#include <stdlib.h>
#include "node.h"

void delete_table(node **htable, unsigned long tabsz) {
    for (unsigned long x = 0; x < tabsz; x++) {
        node *temp = htable[x];
        while (temp != NULL) {
            node *temp2 = temp->next;
            free(temp->id);
            free(temp);
            temp = temp2;
        }
    }
    free(htable);
}