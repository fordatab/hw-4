#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

#define MAX_LINELEN 100 
#define FILE_OPEN_ERR_MSG "error in load_table while opening file %s\n"
#define DUPLICATE_ID_MSG "load_table duplicate entry: %s\n"
#define INSERTION_ERROR_MSG "load_table could not create node for %s\n"

int load_table(node **htable, unsigned long int tabsz, char *filename) {
    FILE *fp = NULL;
	if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, FILE_OPEN_ERR_MSG, filename);
        return -1;
    }

	char buf[MAX_LINELEN + 1]; // input buffer for fgets
	while (fgets(buf, MAX_LINELEN + 1, fp) == buf) {
        char *token = strtok(buf, ",");
        char *id = token;
        token = strtok(NULL, ",");
        double x = atof(token);
        token = strtok(NULL, ",");
        double y = atof(token);
        int index = hash(id)%tabsz;
        if (node_lookup(htable[index], id) == NULL) {
            htable[index] = insert_node(htable[index], id, x, y);
            if (htable[index] == NULL) {
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