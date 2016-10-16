#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node
{
	int key_2;
	int value;
	struct node *prev;
	struct node *next;
	struct node *down;
	struct node *up;
} NODE;

typedef struct header
{
	struct header *up;
	struct header *down;
	struct node *list;
} HEADER;

NODE * insert_node(HEADER * base,int key_2,int value);
HEADER * create_list();
int insert_nextlvl(HEADER * next_hdr,HEADER * prev_hdr,NODE * prev_node);

int max_lvl=0;

HEADER * create_list()
{
	HEADER * new_list=(HEADER *)malloc(sizeof(HEADER));
	
	new_list->up=NULL;
	new_list->down=NULL;
	new_list->list=NULL;

	max_lvl++;

	return new_list;
}

NODE * insert_node(HEADER * base,int key_2,int value)
{
	NODE * new_node=(NODE *)malloc(sizeof(NODE));
	NODE * curr_node;
	NODE * prev_node;

	int flip;

	time_t seed_rand;

	srand((unsigned)time(&seed_rand));

	new_node->key_2=key_2;
	new_node->value=value;
	new_node->prev=NULL;
	new_node->next=NULL;
	new_node->up=NULL;
	new_node->down=NULL;

	if(base->list==NULL)
	{
		base->list=new_node;
	}
	else
	{
		curr_node=base->list;

		if(curr_node->key_2>new_node->key_2)
		{
			base->list=new_node;
			new_node->next=curr_node;
			curr_node->prev=new_node;
		}
		else
		{
			while(curr_node!=NULL)
			{
				if(curr_node->key_2<new_node->key_2)
				{
					prev_node=curr_node;
					curr_node=curr_node->next;
				}
				else if(curr_node->key_2==new_node->key_2)
				{
					prev_node=curr_node;
					curr_node=curr_node->next;
					break;
				}
				else
				{
					break;
				}
			}
			if(curr_node==NULL)
			{
				prev_node->next=new_node;
				new_node->prev=prev_node;
			}
			else
			{
				prev_node->next=new_node; //seg fault as less than codition not handled..
				new_node->prev=prev_node;
				new_node->next=curr_node;
				curr_node->prev=new_node;
			}
		}
	}

	flip=rand()%2;
	
	if (flip==1)
	{
		insert_nextlvl(base->up,base,new_node);
	}

	return new_node;
}

int insert_nextlvl(HEADER * next_hdr,HEADER * prev_hdr,NODE * prev_node)
{
	
	NODE * new_node;

	if(next_hdr==NULL)
	{
		if(max_lvl<20)
		{
			next_hdr=create_list();
		}
		else
		{
			return -1;
		}

		next_hdr->down=prev_hdr;
		prev_hdr->up=next_hdr;
	}
	
	new_node=insert_node(next_hdr,prev_node->key_2,prev_node->value);

	new_node->down=prev_node;
	prev_node->up=new_node;

	return 0;
}