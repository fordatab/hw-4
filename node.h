#ifndef _NODE_H
#define _NODE_H

typedef struct node {
	char *id;
	double xcoord;
	double ycoord;
	struct node *next;
} node;

extern node *node_lookup(node *front, char *id);
extern node *insert_node(node *front, char *id, double xcoord, double ycoord);
extern int load_table(node **htable, unsigned long tabsz, char *filename);
extern unsigned long hash(char *id);
extern void delete_table(node **htable, unsigned long tabsz);
extern void print_info(node **htable, unsigned long tabsz);

#endif
