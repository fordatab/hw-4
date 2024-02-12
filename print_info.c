#include <stdio.h>
#include <limits.h>
#include "node.h"

#define TABSZ_MSG "Table size: %lu\n"
#define TOTAL_ENTRIES_MSG "Total entries: %lu\n"
#define LONGEST_MSG "Longest chain: %lu\n"
#define SHORTEST_MSG "Shortest chain: %lu\n"
#define EMPTY_MSG "Empty buckets: %lu\n"
#define TREES_WITHIN_REGION_MSG "Total trees within given region: %lu\n"


void print_info(node **htable, unsigned long tabsz) {
    long node_count = 0;
    long longest_chain = 0;
    long shortest_chain = 0;
    long empty_buckets = 0;

    for (unsigned long x = 0; x < tabsz; x++) {
        node *temp = htable[x];
        int nodes = 0;
        while (temp != NULL) {
            temp = temp->next;
            nodes++;
            node_count++;
        }
        if (nodes == 0) {
            empty_buckets++;
        }
        if (nodes > longest_chain) {
            longest_chain = nodes;
        }
        if (x == 0) {
            shortest_chain = nodes;
        }
        if (nodes < shortest_chain) {
            shortest_chain = nodes;
        }
    }
    printf(TABSZ_MSG, tabsz);
    printf(TOTAL_ENTRIES_MSG, node_count);
    printf(LONGEST_MSG, longest_chain);
    printf(SHORTEST_MSG, shortest_chain);
    printf(EMPTY_MSG, empty_buckets);
}
