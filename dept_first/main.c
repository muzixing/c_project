
#include <stdlib.h>
#include <stdio.h>
#include "dept_first.h"
#include "tree.h"

int main()
{	
	int array[] = {4,1,5,3,7,8,2,9,10,11};
	/*
							4
						1		5
					3	 7	  8	   2
				9	10	11

			9 3 10 1 7 11 4 8 5 2
	*/
	int len = 10;
	tree_t* tree_array = tree_create(array,len);//creat a tree.

	link_t* root =  DFS2LINK(tree_array);
	print_link(root);

	return 0;
}
