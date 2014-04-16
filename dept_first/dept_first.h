#ifndef _DEPT_FIRST_
#define _DEPT_FIRST_
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

typedef struct link{
	int data;
	struct link* next;

}link_t;
void dept_first_traversal(tree_t* node);
link_t* DFS2LINK(tree_t* node);
void print_link(link_t* node);

#endif