#include <stdio.h>
#include <stdlib.h>

struct node
{
    void* item;
    struct node* next;
};

struct node* create(void* item)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->item = (int*) item;
    newnode->next = NULL;

    return newnode;
}

struct node* add_int(struct node* head, void* item)
{
    struct node* newnode = create(item);
    newnode->next = head;

    //novo head vai receber newnode
    return newnode;
}

void addEnd_int(struct node** head, void* item)
{
    //tem que usar ponteiro para ponteiro porque assim mudarei o head dentro da função
    struct node* newnode = create(item);

    //lista vazia
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }

    //encontrar o último nó
    struct node* last = *head;

    while(last->next != NULL)
        last = last->next;
    //o next do último nó vai receber o ponteiro para o novo nó que criamos com a função
    last->next = newnode;
}

void addEnd_tail_int(struct node** head, struct node** tail, void* item)
{
    struct node* newnode = create(item);

    if(*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
        return;
    }
    //mudando o next da cauda para receber o novo nó que criamos com a função
    (*tail)->next = newnode;
    //atualizando a nova cauda
    *tail = newnode;
}


int main()
{
    struct node* head = NULL;
    struct node* tail = NULL;
    
    //int item = 3;

    /*HEAD CONSTANTEMENTE ATUALIZADO PORQUE ADICIONA-SE NA CABEÇA */
    //head = add_int(head, &item);

    /*COMO PRINTAR COM CAST*/
    //printf("%d\n", *(int*)(head->item));
    
    free(head);
    free(tail);
    return 0;
}