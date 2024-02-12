#include <stdlib.h>
#include <stdio.h>
#include "node.h"

int main(int argc, char **argv) {
      (void) argv;
      (void) argc;
	node **htable = calloc(2, sizeof(node*));
	htable[0] = insert_node(htable[0], "first", 1, 1);
	htable[0] = insert_node(htable[0], "second", 2, 2);
	htable[0] = insert_node(htable[0], "third", 3, 3);
	htable[1] = insert_node(htable[1], "fourth", 4, 4);
	htable[1] = insert_node(htable[1], "fifth", 5, 5);


   // node *front = htable[0];
   // front = insert_node(front, "first", 1, 1);
  //  front = insert_node(front, "second", 2, 2);
   // front = insert_node(front, "third", 3, 3);
  //  front = insert_node(front, "fourth", 4, 4);
   // front = insert_node(front, "fifth", 5, 5);
	printf("%s\n", htable[0]->id);

    if (node_lookup(htable[1], "fourth") == NULL) {
        printf("%s\n", "not found");
    } else {
        printf("%s\n", "found");
    }
}
