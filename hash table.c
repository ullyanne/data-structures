#include <stdio.h>
#include <stdlib.h>

struct hashNode
{
    int key;
    int value;
    struct hashNode* next;
};

struct hashtable
{
    struct hashNode* ht[13];
    int size;
};

struct hashtable* createHashtable(int size)
{
    struct hashtable* hashTable = (struct hashtable*) malloc(sizeof(struct hashtable));
    hashTable->size = size;

    for(int i = 0; i < size; i++)
        hashTable->ht[i] = NULL;

    return hashTable;
}

struct hashNode* createHashnode(int key, int value)
{
    struct hashNode* node = (struct hashNode*) malloc(sizeof(struct hashNode));
    node->key = key;
    node->value = value;
    node->next = NULL;

    return node;
}

int hash(int key, int size)
{
    return key%size;
}

void put(struct hashtable* ht, int key, int value)
{
    struct hashNode* newnode = createHashnode(key, value);
    int h = hash(key, ht->size);
    newnode->next = ht->ht[h];
    ht->ht[h] = newnode;
}

void putEnd(struct hashtable* ht, int key, int value)
{
    struct hashNode* newnode = createHashnode(key, value);
    int h = hash(key, ht->size);

    if(ht->ht[h] == NULL)
    {
        ht->ht[h] = newnode;
        return;
    }

    struct hashNode* last = ht->ht[h];

    while(last->next != NULL)
        last = last->next;
    
    last->next = newnode;
}

struct hashNode* get(struct hashtable* ht, int key)
{
    int h = hash(key, ht->size);
    struct hashNode* current = ht->ht[h];
    
    while(current != NULL)
    {
        if(current->key == key)
            return current;
        
        current = current->next;
    }

    return NULL;
}

void removeKey(struct hashtable* ht, int key)
{
    int h = hash(key, ht->size);
    struct hashNode* current = ht->ht[h];
    struct hashNode* prev = NULL;

    while(current != NULL && current->key != key)
    {
        prev = current;
        current = current->next;
    }

    if(current == NULL)
    {
        printf("Can't find the desired key to remove.\n");
        return;
    }

    if(prev == NULL)
        ht->ht[h] = current->next;
    else
        prev->next = current->next;

    free(current);
}

void print(struct hashtable* ht)
{
    for(int i = 0; i < ht->size; i++)
    {
        printf("%d -> ", i);

        if(ht->ht[i] != NULL)
        {
            struct hashNode* ptr = ht->ht[i];
            while(ptr != NULL)
            {
                if(ptr->next == NULL)
                    printf("{%d: %d} -> ", ptr->key, ptr->value);
                else
                    printf("{%d: %d} -> ", ptr->key, ptr->value);
                ptr = ptr->next;
            }
        }
        printf("\\\n");
    }
}

int main()
{
    int size = 13;
    struct hashtable* ht = createHashtable(size);

    return 0;
}


