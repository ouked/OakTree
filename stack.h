/// Get head of stack without removing it
/// \param stack Stack to peek from
/// \param stackPointer Pointer for stack
/// \return Top node
extern struct node *peek(struct node *stack[], int *stackPointer);

/// Get head of stack and remove iti
/// \param stack Stack to pop from
/// \param stackPointer Pointer for stack
/// \return Top node
extern struct node *pop(struct node *stack[], int *stackPointer);

/// Get head of stack and remove iti
/// \param stack Stack to pop from
/// \param stackPointer Pointer for stack
/// \return Top node
extern void push(struct node *stack[], int *stackPointer, struct node *n);

/// Create a tree from a filepath.
/// \param path Path to read file from
/// \return Head of tree
extern struct node *treeFromFile(const char *path);