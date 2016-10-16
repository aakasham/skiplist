#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"skiplist.h"

int main()
{
	HEADER * base_node,*head_node;
	NODE * curr_node;

	int key_1,temp;

	time_t seed_rand;

	srand((unsigned)time(&seed_rand));

	base_node=create_list();

	for(int j=0;j<10;j++)
	{
		key_1=rand()%65000;
		printf("%d\n",key_1);
//		temp=key_1;
//		curr_node=insert_node(base_node,temp,30);	
	}
/*	insert_node(base_node,10,20);
	insert_node(base_node,40,2);
	insert_node(base_node,30,3);
	insert_node(base_node,40,4);
	insert_node(base_node,60,5);
	insert_node(base_node,70,6);
	insert_node(base_node,70,7);
	insert_node(base_node,70,8);
	insert_node(base_node,10,9);
	insert_node(base_node,5,10);
*/
/*	head_node=base_node;

	while(head_node!=NULL)
	{	
		curr_node=head_node->list;
		while(curr_node!=NULL)
		{
			printf("(%d,%d) ",curr_node->key_2,curr_node->value);
			fflush(stdout);
			curr_node=curr_node->next;
		}
		head_node=head_node->up;
		printf("\n");
	}
*/
}
