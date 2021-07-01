#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct binaryTree
{
    int item;
    struct binaryTree* left;
    struct binaryTree* right;
};

struct binaryTree* create()
{
    int item;
    scanf("%d", &item);

    if(item == -1)
        return NULL;
    
    struct binaryTree* newBT = (struct binaryTree*) malloc(sizeof(struct binaryTree));
    newBT->item = item;

    newBT->left = create();
    newBT->right = create();

    return newBT;
}

//criar uma árvore a partir de uma string contendo parêntesis
struct binaryTree* addFromString(char* arvore, int* index) 
{
    struct binaryTree* root = NULL;
    
    if(arvore[*index] == '(') 
    {
        *index += 1;
        
        if(arvore[*index] == ')') 
        {
            *index += 1;
            return NULL;
        }

        char digits[20];
        int i;
        
        //coletando os dígitos no formato char
        for(i = 0; arvore[*index] != '('; i++, *index+=1)
            digits[i] = arvore[*index]; 
        
        //adicionando no final da string
        digits[i] = '\0';

        //criar um nó a partir do cast nos dígitos
        root = create(atoi(digits));
        root->left = addFromString(arvore, index);
        root->right = addFromString(arvore, index);
    }
    //Adiciono um valor no meu indice para poder continuar a adicionar os meus filhos
    *index += 1;

    return root;
}

bool isBinary(struct binaryTree* root, struct binaryTree** lastVisited)
{
    if(root != NULL)
    {
        if(!isBinary(root->left, lastVisited))
            return 0;

        if(*lastVisited != NULL)
            if((*lastVisited)->item > root->item)
                return 0;

        *lastVisited = root;

        if(!isBinary(root->right, lastVisited))
            return 0;
    }

    return 1;
}

void inOrder(struct binaryTree* bt)
{
    if(bt != NULL)
    {
        inOrder(bt->left);
        printf("%d ", bt->item);
        inOrder(bt->right);
    }
}

void preOrder(struct binaryTree* bt)
{
    if(bt != NULL)
    {
        printf("%d ", bt->item);
        preOrder(bt->left);
        preOrder(bt->right);
    }
}

void postOrder(struct binaryTree* bt)
{
    if(bt != NULL)
    {
        postOrder(bt->left);
        postOrder(bt->right);
        printf("%d ", bt->item);
    }
}

void print(struct queue* queue)
{
    struct node* ptr = queue->head;
    if(isEmpty(queue))
        printf("Empty queue.");
    
    while(ptr!= NULL)
    {
        printf("%d ", ptr->bt->item);
        ptr = ptr->next;
    }
    printf("\n");
}

//os nós da queue são árvores
void BFS(struct binaryTree* bt, int* currentLevel, int value, struct queue* queue)
{
    enqueue(&queue, bt);
    struct node* ptr;

    while(!isEmpty(queue))
    {
        //checa tudo que está no mesmo nível de profundidade. uma vez por profundidade
        if(queue->head->bt->level > *currentLevel)
        {
            *currentLevel+=1;
            ptr = queue->head;
            
            while(ptr != NULL && ptr->bt->level == *currentLevel)
            {
                if(ptr->bt->item == value)
                {
                    printf("ESTA NA ARVORE\n%d\n", ptr->bt->level);
                    return;
                }

                ptr = ptr->next;
            }
        }

        //empilha os filhos à esquerda e direita
        if(queue->head->bt->left != NULL)
        {
            queue->head->bt->left->level = queue->head->bt->level+1;
            enqueue(&queue, queue->head->bt->left);
        }
        if(queue->head->bt->right != NULL)
        {
            queue->head->bt->right->level = queue->head->bt->level+1;
            enqueue(&queue, queue->head->bt->right);
        }
        
        dequeue(&queue);
    }

    printf("NAO ESTA NA ARVORE\n");
}

int main()
{
    struct binaryTree* root = create();

    return 0;
}