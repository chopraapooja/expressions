typedef struct Stack Stack;
typedef struct s_Node S_Node;

struct s_Node{
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
