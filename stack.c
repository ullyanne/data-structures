#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int item;
    struct node* next;
};

struct stack
{
    struct node* top;
    int size;
};

struct node* createNode(int item)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->item = item;

    return newnode;
}

struct stack* createStack()
{
    struct stack* newstack = (struct stack*) malloc(sizeof(struct stack));
    newstack->top = NULL;
    newstack->size = 0;
    return newstack;
}

bool isEmpty(struct stack* stack)
{
    return stack->size == 0;
}

void push(struct stack** stack, int item)
{
    struct node* newtop = createNode(item);
    newtop->next = (*stack)->top;
    (*stack)->top = newtop;
    (*stack)->size++;
}

struct node* pop(struct stack* stack)
{
    if(isEmpty(stack))
        printf("Stack underflow.\n");
    else
    {
        struct node* currentTop = stack->top;
        stack->top = currentTop->next;
        stack->size--;

        return currentTop;
    }
}

struct node* peek(struct stack* stack)
{
    if(isEmpty(stack))
        printf("Stack underflow.\n");
    else
    {
        return stack->top;
    }
}

void print(struct stack* stack)
{
    struct node* ptr = stack->top;
    if(isEmpty(stack))
        printf("Empty stack.");
    
    while(ptr!= NULL)
    {
        printf("%d ", ptr->item);
        ptr = ptr->next;
    }
    printf("\n");
}

void printPop(struct stack* stack)
{
    if(isEmpty(stack))
        printf("Empty stack.\n");
    while(!isEmpty(stack))
    {
        printf("%d ", pop(stack)->item);
    }
}

int main()
{
    struct stack* stack = createStack();
    
    free(stack);
}