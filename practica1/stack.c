#include "stack.h"
#include <stdlib.h>
Nodo *CrearNodo(char data) {
  Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
  nodo->data = data;
  nodo->siguiente = NULL;
  return nodo;
}
void DestruirNodo(Nodo *nodo) {

  nodo->siguiente = NULL;
  free(nodo);
}
Stack *crearStack() {

  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}
void destruirStack(Stack *stack) {

  while (stack->top != NULL) {

    Desapilar(stack);
  }
  free(stack);
}
void Apilar(Stack *stack, char data) {

  Nodo *nodo = CrearNodo(data);
  nodo->siguiente = stack->top;
  stack->top = nodo;
  stack->longitud++;
}
void Desapilar(Stack *stack) {

  if (stack->top != NULL) {

    Nodo *eliminar = stack->top;
    stack->top = stack->top->siguiente;
    DestruirNodo(eliminar);
    stack->longitud--;
  }
}
char Cima(Stack *stack) {

  if (stack->top == NULL)
    return 'F';
  else
    return stack->top->data;
}
int length(Stack *stack) { return stack->longitud == 0; }
