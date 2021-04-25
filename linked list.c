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

void remove(struct node** head, int item)
{
    struct node* current = *head;
    struct node* prev = NULL;

    while(current != NULL && current->item != item)
    {
        prev = current;
        current = current->next;
    }

    if(current == NULL)
    {
        printf("Can't find the desired node to remove.\n");
        return;
    }

    if(prev == NULL)
        *head = current->next;
    else
        prev->next = current->next;

    free(current);
}

void print(struct node* head)
{
    struct node* ptr = head;

    while(ptr != NULL)
    {
        if(ptr->next == NULL)
            printf("%d", ptr->item);
        else
            printf("%d ", ptr->item);
        ptr = ptr->next;
    }
}

struct node* reverse(struct node* prev, struct node* current)
{
    struct node* next;

    if(current == NULL)
        return prev;
    
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;

    return reverse(prev, current);
}

void swap(struct node* x, struct node* y)
{
    int item;

    item = x->item;
    x->item = y->item;
    y->item = item;
}

void bubblesort(struct node* first)
{
    struct node* ptr;
    struct node* last = NULL;
    int swapped = 0;

    if(first == NULL)
        return;

    do
    {
        ptr = first;
        swapped = 0;

        while(ptr->next != last)
        {
            if(ptr->item > ptr->next->item)
            {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            
            ptr = ptr->next;
        }
        
        last = ptr;
    } while (swapped);
}

int main()
{
    struct node* head = NULL;
    struct node* tail = NULL;

    free(head);
    free(tail);
    return 0;
}