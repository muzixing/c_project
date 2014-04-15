#include <stdlib.h>
#include "grow.h"

tree_t* grow(int *array){
	length = len(array);
	tree_t * tree_array = (tree_t*)malloc(sizeof(tree_t)*length;

	int i = 0
	for (; i< length ; ++i)
	{	
		int* L_child = NULL;
		int* R_child = NULL;
		if (array+i*2<length)   //Add the pointers.
		{
			L_child = array+i*2;
			
		}
		if(array+i*2+1<length)
		{
			R_child = array+i*2+1;
		}

		p = tree_create(*(array+i),L_child,R_child);
		tree_array[i] = p;

		return *tree_array
	}
}