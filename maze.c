#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "stack.h"

int main(int argc, char* argv[]) {
    Node * stack = NULL;
    Node * cur;
    push(1, 1, &stack);
    push(2, 2, &stack);
    push(3, 4, &stack);
    cur = pop(&stack);
    printf("%d|%d\n", cur -> xCor, cur -> yCor);
    free(cur);
    cur = pop(&stack);
    printf("%d|%d\n", cur -> xCor, cur -> yCor);
    free(cur);
    cur = pop(&stack);
    printf("%d|%d\n", cur -> xCor, cur -> yCor);
    free(cur);
}