#include <stdlib.h>
#include <stdio.h>
#include "dept_first.h"

link_t *link_list[12]; //bad design.
int num = 0;
void dept_first_traversal(tree_t* node){
	if (node->L_child!= NULL)
	{
		//printf("go left\n");
		dept_first_traversal((tree_t*)node->L_child);
		
	}
	if (node->flag == 0)
	{
		node->flag = 1;
		//printf("node->data:%d\n", node->data);	
		link_t*  link = (link_t*)malloc(sizeof(link_t));
		
		link->data = node->data;
		//printf("link->data:%d\n",link->data);
		link_list[num++] = link; //save link at array.
	
	}
	if (node->R_child)
	{
		//printf("go right\n");
		dept_first_traversal((tree_t*)node->R_child);
	}
	
}

link_t* DFS2LINK(tree_t* node)
{
	dept_first_traversal(node);
	while(--num)
	{
		link_list[num-1]->next = link_list[num];
		printf("link_list[%d]: %d\n", num,link_list[num]->data);
	} 
	link_list[0]->next =link_list[1];
	printf("link_list[%d]: %d\n", num,link_list[num]->data);
	return *link_list;
}

void print_link(link_t* node)
{
	do
	{
		printf("link_list->data:%d\n:",node->data);
		node = node->next;
	} while (node->next!=NULL);
	printf("link_list->data:%d\n:",node->data);
}

