#include <stdio.h>
#include <stdlib.h>

enum opType{ADD, SUB, MUL, DIV, NEG, NUM, ERR};

struct node {
    enum opType type;
    int data;
    struct node *left;
    struct node *right;
};

// create a new op node 
// data = 0 if read
extern struct node *newOpNode(enum opType optype);


// create a new num node
// no children
extern struct node *newNumNode(int data);


// check if node is safe ((num) or (operator with 2 valid children))
extern int isSafe(struct node *n);


// evaluates node 
extern int valueOf(struct node *n);
