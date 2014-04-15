#include <stdlib.h>
#include "link.h"
#include <stdio.h>

void insert(link_t* root,int data,int n){
	link_t* p = link_create(); //create a pointer.
	p = root;
	while (n-2) //post_insert.
	{
		n--;
		p = p->next;
	}
	link_t* node = link_create();
	node->next = p->next;
	p->next = node;
	node->data = data;
}

link_t* link_create(){
	link_t* p = (link_t*)malloc(sizeof(link_t));
	return p;
}