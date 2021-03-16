#include <stdio.h>

#include "util.h"
#include "node.h"
#include "stack.h"
#include "test.h"

int main(void) {
    struct node *root = treeFromFile("values.txt");
    printf("%d\n", valueOf(root));

    runTests();
    return 0;
}