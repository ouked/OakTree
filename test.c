#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#include "node.h"
#include "stack.h"
#include "util.h"

void writeFile(const char *path, const char *data) {
    FILE *f;
    if((f = fopen(path, "w")) == NULL)
    {
        printf("Unable to create file\n");
        return;
    }
    fputs(data, f);
    fclose(f);
}

const char green[] = "\e[0;32m";
const char red[] = "\e[0;31m";
const char reset[] = "\033[0m";
const char path[] = "test_file.txt";
int failed;
int counter;


bool fileExists(const char *path){
    FILE *f;
    if ((f = fopen(path, "r"))) {
        fclose(f);
        return true;
    }
    return false;

}

void test(const char *input, int expected){
    
    counter++;
    writeFile(path, input);
    int actual;
    struct node *root = treeFromFile(path);
    if ((actual=valueOf(root)) == expected) {
        printf("%sTest %02d passed.\n", green, counter);
    } else {
        failed++;   
        printf("%sTest %02d failed.\n", red, counter);
        printf("\tTest: %s\n", input);
        printf("\tExpected Output: %d\n", expected);
        printf("\tActual Output: %d\n", actual);
    }
    printf("%s", reset);
}
void runTests() {
    if (fileExists(path)) {
        printError("Test file already exists.\n");
        return;
    }
    printf("Running tests...\n\n");
    failed = 0;
    counter = 0;
    // Tests:
    test("", 0);
    test("6", 6);
    test("4 2 5 * + 1 3 2 * + /", 2);
    test("5 1 2 + 4 * 3 - +", 14);
    test("6 5 6 * + 6 /", 6);
    test("1  ", 1);
    test(" 1 ", 1);
    test("  1", 1);
    if (failed != 0) {
        printf("\n\n%s%d test(s) failed out of %d.\n", red, failed, counter);
    } else {
        printf("\n\n%sSuccess! All %d tests passed.\n", green, counter);
    }
    remove(path);
}