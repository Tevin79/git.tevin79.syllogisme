#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 3

#include "writing.h"
#include "displayConsole.h"

int main(void)
{
    bool next = true;
    char **propTable = initProp();
    while (next) {

        printPropChoice(propTable);

        next = false;
    }
    freeProp(propTable);
    return EXIT_SUCCESS;
}
