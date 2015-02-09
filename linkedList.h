typedef struct Node Node;
typedef struct LinkedList LinkedList;
typedef int (Predicate)(void *);
typedef void (Operation) (void *);

struct Node{
	void *data;
	void *next;
};

struct LinkedList
{
	Node *head;
	Node *tail;
	int count;
};
int _add_to_list(LinkedList *list, void *data);
Node* create_node(void *data);
LinkedList createList(void);
int add_to_list(LinkedList *,Node *);
void* get_first_element(LinkedList list);
void* get_last_element(LinkedList list);
void traverse(LinkedList, void (*)(void *data));
void * getElementAt(LinkedList, int );
int indexOf(LinkedList, void *);
int asArray(LinkedList, void **);
void * deleteElementAt(LinkedList*, int);
LinkedList * filter(LinkedList, Predicate);
void printList(LinkedList list);
// void traverse(LinkedList, Operation);

int parseInt(void *ref);
char* parseString(void *ref);