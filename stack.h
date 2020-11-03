#ifndef STACK_H
#define STACK_H

typedef struct stackNode{
    int xCor;
    int yCor;
    struct stackNode* next;
} Node;

void push(int xCor, int yCor, Node ** head);

Node * pop(Node ** head);

#endif	