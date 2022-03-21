#pragma once
#include <stdio.h>
typedef struct Node
{
  char data;
  int row;
  int col;
  struct Node *nextNode;
} Node;
typedef struct stack
{
  Node *top;
  int length;
} Stack;

Node *createNode(char data, int dataRow, int dataCol);
Stack *createStack();
void destroyStack(Stack *stack);

void destroyNode(Node *Node);
void push(Stack *stack, char data, int dataRow, int dataCol);
void pop(Stack *stack);
char top(Stack *stack);
int lengthOfStack(Stack *stack);
int isEmpty(Stack *stack);
