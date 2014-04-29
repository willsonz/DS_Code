/*********************************************
 * Main Program for test algorihm
 *
 * ******************************************/

#include <stdio.h>
#include <stdlib.h>

// HString
#include "hstring.h"

int main()
{
    HString T;
    T.ch = NULL;
    T.length = 0;

    if (StrAssign(T, "That's a text"))
        printf("Successful!\n");
    else
        printf("Error!\n");

    // StringAssign test
    return 0;
}
