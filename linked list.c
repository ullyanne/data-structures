#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node* next;
};

struct node* create(int item)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->item = item;
    newnode->next = NULL;

    return newnode;
}

struct node* add(struct node* head, int item)
{
    struct node* newnode = create(item);
    newnode->next = head;

    return newnode;
}

void addEnd(struct node** head, int item)
{
    struct node* newnode = create(item);

    if(*head == NULL)
    {
        *head = newnode;
        return;
    }

    struct node* last = *head;

    while(last->next != NULL)
        last = last->next;
    
    last->next = newnode;
}

void addEnd_tail(struct node** head, struct node** tail, int item)
{
    struct node* newnode = create(item);

    if(*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
        return;
    }

    (*tail)->next = newnode;
    *tail = newnode;
}


int main()
{
    struct node* head = NULL;
    struct node* tail = NULL;

    free(head);
    free(tail);
    return 0;
}