// returns head of stack without removing it
extern struct node *peek(struct node *stack[], int *stackPointer);

// returns head of stack and removes it
extern struct node *pop(struct node *stack[], int *stackPointer);

// adds node to stack
extern void push(struct node *stack[], int *stackPointer, struct node *n);

// create tree from file at path
extern struct node *treeFromFile(const char *path);