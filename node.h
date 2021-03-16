#include <stdio.h>
#include <stdlib.h>

/// Types of Operations
enum opType{ADD, SUB, MUL, DIV, NEG, NUM, ERR};

/// Node structure.
struct node {
    enum opType type;
    int data;
    struct node *left;
    struct node *right;
};

/// Create a new operation node
/// \param optype Type of operation
/// \return New node
extern struct node *newOpNode(enum opType optype);


/// Create a new number node
/// \param data Value of new node
/// \return New node
extern struct node *newNumNode(int data);


/// Check if a node is safe ((number node) or (operator node with 2 valid children))
/// \param n Node to check
/// \return True if the node is safe
extern int isSafe(struct node *n);


/// Evaluates the value of a node
/// \param n Node to evaluate
/// \return Value of the given node
extern int valueOf(struct node *n);
