#ifndef _TREE_
#define _TREE_

typedef struct tree_t
{
	int data;
	int flag;
	struct tree_t* L_child;
	struct tree_t* R_child;
}tree_t;
void tree_destroy(tree_t* tree);
tree_t* tree_mod(tree_t* tree,int data);
tree_t* tree_create(int *array,int len);

#endif
