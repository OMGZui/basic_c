/*  nogood.c -- a program with errors */
#include <stdio.h>
int main(void)
// “First, it uses parentheses instead of braces”
(
    // “Second, the declaration should have been int n, n2, n3;”
    int n, int n2, int n3;

// “Next, omits the */ symbol pair necessary to complete a comment”
/* this program has several errors
    n = 5;
    n2 = n * n;
    n3 = n2 * n2;
    // “Finally, omits the mandatory semicolon that should terminate the printf() statement”
    printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3)

    return 0;
)
