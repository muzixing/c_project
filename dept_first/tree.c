#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

void tree_destroy(tree_t * tree){
	free(tree);
}

tree_t* tree_mod(tree_t* tree,int data){
	tree->data = data;
	return tree;
}
tree_t* tree_create(int *array,int len)
{	
	tree_t * tree_array = (tree_t*)malloc(sizeof(tree_t)*len);

	int i = 0;
	for (; i< len; i++)
	{	
		tree_t* L_child = NULL;
		tree_t* R_child = NULL;
		tree_array[i].data = array[i]; //
		//printf("tree_array[%d]->data:%d\n", i,array[i]);
		if (i*2<len-1)                             //Add the pointers. pay attention at here!! critical size.
		{
			L_child = (tree_array+i*2+1);
			//printf("L_child is %p\n",L_child );
		}
		if(i*2+1<len-1)
		{
			R_child = tree_array+i*2+2;
			//printf("R_child is %d\n",*R_child );
		}
		tree_array[i].L_child = L_child;
		tree_array[i].R_child = R_child;	
	}
	return tree_array;
}