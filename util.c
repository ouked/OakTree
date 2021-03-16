#include <stdio.h>
#include "util.h"


void printError(const char *msg) {
    printf("\033[0;31m");
    printf("ERROR: %s", msg);
    printf("\033[0m");
}


int toInt(char c) { return c - '0'; }