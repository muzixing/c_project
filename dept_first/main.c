#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "dept_first.h"

int main()
{	
	int array[] = {4,2,5,3,7,8,2,9,10,11};
	int len = 10;
	tree_t* tree_array = tree_grow(array,len);//creat a tree.
	printf("%s\n","yes" );

	link_t* root =  DFS2LINK(tree_array);
	print_link(root);

	return 0;
}
