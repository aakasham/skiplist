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