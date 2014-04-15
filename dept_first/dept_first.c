#include <stdlib.h>
#include <stdio.h>
#include "dept_first.h"

link_t link_list[12];//need to fix the number by other better way.
int i = 0;


void dept_first_traversal(tree_t* node){
	if (node->L_child!= NULL)
	{
		dept_first_traversal((tree_t*)node->L_child);
	}
	if (node->flag == 0)
	{
		node->flag = 1;
		printf("%d:", node->data);	
		link_t * link = (link_t*)malloc(sizeof(link_t));
		link->data = node->data;
		link_list[i++] = *link; //
	}

	if (node->R_child)
	{
		dept_first_traversal((tree_t*)node->R_child);/* code */
	}
	
}

link_t* DFS2LINK(tree_t* node)
{
	dept_first_traversal(node);
	while(i)
	{
		link_list[i-1].next = (int*)link_list;
		i--;
	}
	return link_list;
}

void print_link(link_t* node)
{
	while (node->next!=NULL)
	{
		printf("%d:",node->data);
	}

}

