typedef void* voidPtr;
typedef struct node Node;
typedef Node * Node_ptr;
typedef struct linkedList LinkedList;

struct linkedList{
	Node_ptr head;
	Node_ptr tail;
	int count;
};

struct node {
    voidPtr data;
    Node *next;
};

LinkedList createList(void);
Node * create_node(void *data);
int add_to_list(LinkedList *,Node *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void traverse(LinkedList, void (*)(void *data));