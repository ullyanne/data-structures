#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int item;
    struct node* next;
};

struct queue
{
    struct node* head;
    struct node* tail;
    int size;
};

struct node* createNode(int item)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->item = item;

    return newnode;
}

struct queue* createQueue()
{
    struct queue* newqueue = (struct queue*) malloc(sizeof(struct queue));
    newqueue->head = NULL;
    newqueue->tail = NULL;
    newqueue->size = 0;
    return newqueue;
}

bool isEmpty(struct queue* queue)
{
    return queue->size == 0;
}

void enqueue(struct queue** queue, int item)
{
    struct node* newtail = createNode(item);
    (*queue)->size++;

    if((*queue)->head == NULL)
    {
        (*queue)->head = newtail;
        (*queue)->tail = newtail;
        return;
    }
    
    (*queue)->tail->next = newtail;
    (*queue)->tail = newtail;
}

struct node* dequeue(struct queue** queue)
{
    if(isEmpty(*queue))
        printf("Queue underflow.\n");
    else
    {
        struct node* dequeued = (*queue)->head;
        
        (*queue)->head = (*queue)->head->next;
        (*queue)->size--;

        if((*queue)->head == NULL)
            (*queue)->tail == NULL;
        
        return dequeued;
    }
}

void print(struct queue* queue)
{
    struct node* ptr = queue->head;
    if(isEmpty(queue))
        printf("Empty queue.");
    
    while(ptr!= NULL)
    {
        printf("%d ", ptr->item);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    struct queue* queue = createQueue();

    free(queue);

    return 0;
}