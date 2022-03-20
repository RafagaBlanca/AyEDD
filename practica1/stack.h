#pragma once

#include <stdio.h>
typedef struct Node {
  char data;
  struct Node *nextNode;
} Node;
typedef struct stack {
  Node *top;
  int length;
} Stack;

Node *createNode(char data);
Stack *createStack();
void destroyStack(Stack *stack);

void destroyNode(Node *Node);
void push(Stack *stack, char data);
void pop(Stack *stack);
char top(Stack *stack);
int lengthOfStack(Stack *stack);
int isEmpty(Stack *stack);
