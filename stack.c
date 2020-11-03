#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(int newXCor, int newYCor, Node ** head) {
    Node * new = malloc(sizeof(Node));
    new -> xCor = newXCor;
    new -> yCor = newYCor;
    new -> next = *head;
    *head = new;
}


Node * pop(Node ** head) {
    if(head == NULL) {
        return NULL;
    }
    Node * popped = *head;
    *head = (*head) -> next;
    return popped;
}