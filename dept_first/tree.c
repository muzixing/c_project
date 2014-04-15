#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

tree_t* tree_create(int data, int * L_child,int* R_child){
	tree_t* p = (tree_t*)malloc(sizeof(tree_t));
	p->data = data;
	p->flag = 0;  //flag use for traversal.
	p->L_child = L_child;
	p->R_child = R_child;
	return p;
}

void tree_destroy(tree_t * tree){
	free(tree);
}

tree_t* tree_mod(tree_t* tree,int data){
	tree->data = data;
	return tree;
}
tree_t* tree_grow(int *array,int len)
{	
	printf("%d\n",len);
	tree_t * tree_array = (tree_t*)malloc(sizeof(tree_t)*len);

	int i = 0;
	for (; i< len; i++)
	{	
		int* L_child = NULL;
		int* R_child = NULL;
		if (i*2<=len)   //Add the pointers.
		{
			L_child = array+i*2+1;

			//printf("L_child is %d\n",*L_child );
			
		}
		if(i*2+1<=len)
		{
			R_child = array+i*2+2;
			//printf("R_child is %d\n",*R_child );
		}

		tree_t* p = tree_create(*(array+i),L_child,R_child);

		printf("%d",p->data);
		printf(",");

		tree_array[i] = *p;	
	}
	return tree_array;
}