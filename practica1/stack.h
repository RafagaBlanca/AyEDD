#pragma once

#include <stdio.h>
typedef struct nodo {
  char data;
  struct nodo *siguiente;
} Nodo;
typedef struct stack {
  Nodo *top;
  int longitud;
} Stack;

Nodo *CrearNodo(char data);
Stack *crearStack();
void destruirStack(Stack *stack);

void DestruirNodo(Nodo *nodo);
void Apilar(Stack *stack, char data);
void Desapilar(Stack *stack);
char Cima(Stack *stack);
int length(Stack *stack);
int isEmpty(Stack *stack);
