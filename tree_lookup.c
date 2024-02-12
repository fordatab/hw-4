#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "node.h"

#define MIN_TAB_SZ 3
#define DEFAULT_TAB_SZ 1873
#define QUERY_SUCCESS_FORMAT "found tree id=%s, x=%.5f, y=%.5f\n" 
#define QUERY_FAILURE_FORMAT "could not find tree with id=%s\n"

int main(int argc, char **argv) {
	int s_flag = 0;
	unsigned long tabsz = DEFAULT_TAB_SZ;
    int query_successes = 0;
    char *filename;
    int c;
    while((c = getopt(argc, argv, "st:")) != -1) {
        switch (c) {
            case 's':
                s_flag = 1;
                break;
            case 't':
                if (atol(optarg) >= MIN_TAB_SZ) {
                    tabsz = atol(optarg);
                }
                break;
            default:
                abort();
        }
    }
    filename = argv[optind];
    node **htable = calloc(tabsz, sizeof(node*));
	if (htable == NULL) {
		return EXIT_FAILURE;
	}

	if (load_table(htable, tabsz, filename) != 0) {
		fprintf(stderr, "error in load_table\n");
		free(htable);
		return EXIT_FAILURE;
	}

	size_t bufsz = 0;
	char *buf = NULL;

	ssize_t bytes;
	while ((bytes = getline(&buf, &bufsz, stdin)) > 0) {
        if (buf[bytes - 1] == '\n') buf[bytes - 1] = '\0';
        node *n;
        if ((n = node_lookup(htable[hash(buf)%  tabsz], buf)) == NULL) {
            printf(QUERY_FAILURE_FORMAT, buf);
        } else {
            query_successes++;
            printf(QUERY_SUCCESS_FORMAT, buf, n->xcoord, n->ycoord);
        }
    }
	printf("%d successful queries\n", query_successes);

	if (s_flag == 1) {
        print_info(htable, tabsz);
	}

    delete_table(htable, tabsz);
	free(buf);

	return EXIT_SUCCESS;
}