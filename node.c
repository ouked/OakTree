#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "util.h"

// create a new op node 
// data = 0 if read
struct node *newOpNode(enum opType optype) {
    struct node *node = (struct node * ) malloc(sizeof(struct node));
    node -> type = optype;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

// create a new num node
// no children
struct node *newNumNode(int data) {
    struct node *node = (struct node * ) malloc(sizeof(struct node));
    node -> data = data;
    node -> type = NUM;
    return node;
}

// check if node is safe ((num) or (operator with 2 valid children))
int isSafe(struct node *n) {
    return !(n -> type != NUM && (n -> left == NULL || n -> right == NULL || n->left->type == ERR || n->right->type == ERR));
}

// evaluates node 
int valueOf(struct node *n) {
    if (!isSafe(n)){
        printError("UNSAFE NODE\n");
        return 0;
    }
    switch (n -> type) {
        case NUM:
            return n -> data;
        case ADD:
            return (valueOf(n->left) + valueOf(n->right)); 
        case SUB:
            return (valueOf(n->left) - valueOf(n->right));
        case DIV:
            return (valueOf(n->left) / valueOf(n->right));
        case MUL:
            return (valueOf(n->left) * valueOf(n->right));
        case NEG:
            return (valueOf(n->left) * -1);
        case ERR:
            printError("ERROR NODE IN TREE\n");
            return 0;
        default:
            printError("UNHANDLED OP TYPE\n");
            return 0;
    }
}