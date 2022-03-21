#include <stdio.h>
#include "stack.h"
FILE *loadFile()
{
    FILE *file;
    file = fopen("test.c", "r");
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

int main()
{
    FILE *file = loadFile();
    Stack *brackets = bracketStack();
    fillBracketStack(brackets, file);
    freeMemory(brackets);
}