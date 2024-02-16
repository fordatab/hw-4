#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

#define MAX_LINELEN 100 
#define FILE_OPEN_ERR_MSG "error in load_table while opening file %s\n"
#define DUPLICATE_ID_MSG "load_table duplicate entry: %s\n"
#define INSERTION_ERROR_MSG "load_table could not create node for %s\n"

int load_table(node **htable, unsigned long int tabsz, char *filename) {
    // Create FILE pointer
    FILE *fp = NULL;
    // Open file
	if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, FILE_OPEN_ERR_MSG, filename);
        return -1;
    }
    // Input buffer for fgets
	char buf[MAX_LINELEN + 1];
    // Get line using fgets
	while (fgets(buf, MAX_LINELEN + 1, fp) == buf) {
        // Get the first token
        char *token = strtok(buf, ",");
        char *id = token;
        // Get the next token
        token = strtok(NULL, ",");
        double x = atof(token);
        // Get the next token
        token = strtok(NULL, ",");
        double y = atof(token);
        // Get the hash value
        int index = hash(id)%tabsz;
        // Find if already in table
        if (node_lookup(htable[index], id) == NULL) {
            // Insert into table
            htable[index] = insert_node(htable[index], id, x, y);
            // Check if successfully added
            if (node_lookup(htable[index], id) == NULL) {
                printf(INSERTION_ERROR_MSG, id);
                return -1;
            }
        } else {
            printf(DUPLICATE_ID_MSG, id);
        }
	}
	fclose(fp);
	return 0;
}