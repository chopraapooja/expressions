typedef struct Stack Stack;
typedef struct S_Node S_Node;

struct S_Node{
	void *data;
	S_Node *back;
};

struct Stack {
	S_Node* top;
	int height;
};

Stack createStack(void);
int push(Stack*, void *);
void * pop(Stack *);
void printStack(Stack stack);
S_Node* createNode(void *data);
