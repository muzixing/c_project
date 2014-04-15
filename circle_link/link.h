#ifndef _LINK_
#define _LINK_

typedef struct link
{
	int data;
	struct link* next;
}link_t;

void insert(link_t* root,int data,int n);
link_t* link_create();
void link_delete(int n);

#endif