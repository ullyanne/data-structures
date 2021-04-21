#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nodeP
{
    int item;
    int priority;
    struct nodeP* next;
};

struct queueP
{
    struct nodeP* head;
    int size;
};

struct nodeP* createnodeP(int item, int priority)
{
    struct nodeP* newnode = (struct nodeP*) malloc(sizeof(struct nodeP));
    newnode->item = item;
    newnode->priority = priority;

    return newnode;
}

struct queueP* createqueueP()
{
    struct queueP* newqueue = (struct queueP*) malloc(sizeof(struct queueP));
    newqueue->head = NULL;
    newqueue->size = 0;
    return newqueue;
}

bool isEmptyP(struct queueP* queue)
{
    return queue->size == 0;
}

void enqueueP(struct queueP** queue, int item, int priority)
{
    struct nodeP* newnode = createnodeP(item, priority);
    (*queue)->size++;

    if((*queue)->head == NULL)
    {
        newnode->next = (*queue)->head;
        (*queue)->head = newnode;
        return;
    }
    else if(priority > (*queue)->head->priority)
    {
        newnode->next = (*queue)->head;
        (*queue)->head = newnode;
        return;
    }
    
    struct nodeP* current = (*queue)->head;

    while(current->next != NULL && priority < current->next->priority)
    {
        current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
}

struct nodeP* dequeueP(struct queueP** queue)
{
    if(isEmptyP(*queue))
        printf("Queue underflow.\n");
    else
    {
        struct nodeP* dequeued = (*queue)->head;
        
        (*queue)->head = (*queue)->head->next;
        (*queue)->size--;
        
        return dequeued;
    }
}

void printP(struct queueP* queue)
{
    struct nodeP* ptr = queue->head;
    if(isEmptyP(queue))
        printf("Empty queue.");
    
    while(ptr!= NULL)
    {
        printf("%d ", ptr->priority);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    struct queueP* queueP = createqueueP();
    
    free(queueP);

    return 0;
}