#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
FILE *loadFile(int opc)
{
    FILE *file;
    if (opc == 1)
    {
        file = fopen("1.c", "r");
    }
    if (opc == 2)
    {
        file = fopen("2.c", "r");
    }
    if (opc == 3)
    {
        file = fopen("3.c", "r");
    }
    if (opc == 4)
    {
        file = fopen("4.c", "r");
    }

    if (file == NULL)
    {
        return 0;
    }
    return file;
}
Stack *bracketStack()
{
    Stack *stack = createStack();
    return stack;
}
void Error1(Stack *stack)
{
    if (isEmpty(stack))
    {
        puts("Stack vacia");
        return;
    }
    else
    {
        printf("Falta cerrar el %c de la linea %d col %d\n", stack->top->data, stack->top->row, stack->top->col);
        return;
    }
}
void Error2(char x, int row, int col)
{
    printf("Falta abrir el %c antes de la linea %d col %d", x, row, col);
    return;
}
void Error3(Stack *stack, char x, int row, int col)
{
    printf("El %c que esta en la linea %d col %d ", x, row, col);
    printf("no es el mismo tipo que ");
    printf("%c de la linea %d col %d\n", stack->top->data, stack->top->row, stack->top->col);
}
void fillBracketStack(Stack *bracketStack, FILE *file)
{
    char x;
    int row = 1;
    int col = 0;
    while (x != EOF)
    {
        x = fgetc(file);
        if (x == '\n')
        {
            row++;
            col = 0;
        }
        if (x != '\n')
        {
            col++;
        }
        if (x == '(' || x == '{' || x == '[')
        {
            push(bracketStack, x, row, col);
        }
        if ((x == '}' || x == ')' || x == ']') && isEmpty(bracketStack))
        {
            Error2(x, row, col);
            return;
        }
        if (x == ')' && bracketStack->top->data == '(')
        {
            pop(bracketStack);
        }
        else if (x == ')' && bracketStack->top->data != '(')
        {
            Error3(bracketStack, x, row, col);
            return;
        }
        if (x == ']' && bracketStack->top->data == '[')
        {
            pop(bracketStack);
        }
        else if (x == ']' && bracketStack->top->data != '[')
        {
            Error3(bracketStack, x, row, col);
            return;
        }
        if (x == '}' && bracketStack->top->data == '{')
        {
            pop(bracketStack);
        }
        else if (x == '}' && bracketStack->top->data != '{')
        {
            Error3(bracketStack, x, row, col);
            return;
        }
    }
    Error1(bracketStack);
    return;
}
void freeMemory(Stack *stackToFree)
{
    destroyStack(stackToFree);
}
int printMenu()
{
    int opc;
    do
    {

        system("clear");
        puts("Seleccione el archivo a analizar\n");
        puts("1.- 1.c\n");
        puts("2.- 2.c\n");
        puts("3.- 3.c\n");
        puts("4.- 4.c\n");
        puts("5.- Salir\n");
        scanf("%d", &opc);
        if (opc < 5 && opc > 0)
        {
            return opc;
        }

    } while (opc != 5);
    return opc;
}
int main()
{

    int opc = printMenu();
    FILE *file = loadFile(opc);
    Stack *brackets = bracketStack();
    fillBracketStack(brackets, file);
    freeMemory(brackets);
}