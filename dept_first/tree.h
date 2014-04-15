#ifndef _TREE_
#define _TREE_
#include <stdlib.h>

typedef struct _TREE_
{
	int data;
	int flag;
	int* L_child; 
	int* R_child;
}tree_t;

tree_t* tree_create(int data, int * L_child,int* R_child);
void tree_destroy(tree_t* tree);
tree_t* tree_mod(tree_t* tree,int data);
tree_t* tree_grow(int *array,int len);

#endif
