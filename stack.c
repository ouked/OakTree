#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "node.h"
#include "util.h"
#include "stack.h"


// returns head of stack without removing it
struct node *peek(struct node *stack[], int *stackPointer) {
    return stack[*stackPointer];
}

// returns head of stack and removes it
struct node *pop(struct node *stack[], int *stackPointer) {
    struct node *n = peek(stack, stackPointer);
    stack[(*stackPointer)--] = newOpNode(ERR);
    return n;
}

// adds node to stack
void push(struct node *stack[], int *stackPointer, struct node *n) {
    stack[++(*stackPointer)] = n;
}

// create tree from file at path
struct node *treeFromFile(const char *path) {
    FILE *file;
    file = fopen(path, "r");

    // Check file is valid
    if (!file) {
        printError("INVALID FILEPATH\n");
        return newOpNode(ERR);
    }

    // Character being read
    char c;

    // Stack
    int stackPointer = 0;
    struct node *stack[64];

    // Buffer to read numbers
    int buffer = 0;
    bool bufferEmpty = true;
    //printf("%d\n", valueOf(n));
    
    // Value to be added to stack
    struct node *newNode;

    bool fileEmpty = true;

    // while characters to be read
    while ((c = getc(file)) != EOF) {
        fileEmpty = false;
        if (isdigit(c)) {
            // append c to buffer
            buffer = (buffer*10) + toInt(c);
            bufferEmpty = false;
            continue;
        
        } else if (c == ' ') {
            // ignore space if buffer empty
            if (bufferEmpty) {continue;}

            // create numNode with buffer
            newNode = newNumNode(buffer);
            buffer = 0;
            bufferEmpty = true;

        // Negative Operator
        } else if (c == '~') {
            if (stackPointer == 0) {
                printError("STACK UNDERFLOW\n");
                return newOpNode(ERR);
            }
            newNode = newOpNode(NEG);
            
            // left & right point to same node so that node meets "safe" criteria
            newNode -> left = pop(stack, &stackPointer);
            newNode -> right = newNode -> left;

        // standard operations
        } else {

            // check there are enough nodes to pop
            if (stackPointer < 1) {
                printError("STACK UNDERFLOW\n");
                return newOpNode(ERR);
            }

            // if safe to pop...
            switch (c){
                case '+':
                    newNode = newOpNode(ADD);
                    break;
                case '-':
                    newNode = newOpNode(SUB);
                    break;
                case '/':
                    newNode = newOpNode(DIV);
                    break;
                case '*':
                    newNode = newOpNode(MUL);
                    break;
                default:
                    printError("UNKNOWN CHAR: ");
                    printf("%c", c);
                    return newOpNode(ERR);
            }

            // set left & right pointers to nodes from the stack
            newNode -> right = pop(stack, &stackPointer);    
            newNode -> left = pop(stack, &stackPointer);
        }

        // push new node to stack
        push(stack, &stackPointer, newNode);
    }

    // Push buffer if it's not empty
    if (!bufferEmpty){
        push(stack, &stackPointer, newNumNode(buffer));
        bufferEmpty = true;
    }
    
    // return head of stack (root of tree)
    return fileEmpty ? newNumNode(0) : peek(stack, &stackPointer);
}