#include "stack.h"
#include <stdlib.h>
Node *createNode(char data)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->nextNode = NULL;
  return node;
}
void destroyNode(Node *Node)
{

  Node->nextNode = NULL;
  free(Node);
}
Stack *createStack()
{

  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}
void destroyStack(Stack *stack)
{

  while (stack->top != NULL)
  {

    pop(stack);
  }
  free(stack);
}
void push(Stack *stack, char data)
{

  Node *Node = CrearNode(data);
  Node->nextNode = stack->top;
  stack->top = Node;
  stack->length++;
}
void pop(Stack *stack)
{

  if (stack->top != NULL)
  {

    Node *delete = stack->top;
    stack->top = stack->top->nextNode;
    DestruirNode(delete);
    stack->length--;
  }
}
char top(Stack *stack)
{

  if (stack->top == NULL)
    return 'F';
  else
    return stack->top->data;
}
int lengthOfStack(Stack *stack) { return stack->length == 0; }
