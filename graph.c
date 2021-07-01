#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct graph
{
    struct node** adjacencyList;
    bool* visited;
    int* predecessor;
    int* distance;
    int size;
};

struct graph* createGraph(int size)
{
    struct graph* newgraph = (struct graph*) malloc(sizeof(struct graph));
    newgraph->adjacencyList = (struct node**) malloc(size * sizeof(struct node*));
    newgraph->visited = (bool*) malloc(size* sizeof(bool));
    newgraph->predecessor = (int*) malloc(size* sizeof(int));
    newgraph->distance = (int*) malloc(size* sizeof(int));
    newgraph->size = size;

    for(int i = 0; i < size; i++)
    {
        newgraph->adjacencyList[i] = NULL;
        newgraph->visited[i] = false;
        newgraph->predecessor[i] = -1;
        newgraph->distance[i] = -1;
    }

    return newgraph;
}

void adjList(struct node** adjacencyList, int* values, int times)
{
    int value, nodeleft, noderight;
    
    for(int i = 0; i < times; i++)
    {
        adjacencyList[i] = NULL;
        scanf("%d%d%d", &value, &nodeleft, &noderight);
        values[i] = value;

        addEnd(adjacencyList, i, nodeleft);
        addEnd(adjacencyList, i, noderight);
    }
}

void clear(struct graph* graph)
{
    for(int i = 0; i < graph->size; i++)
    {
        graph->visited[i] = false;
        graph->predecessor[i] = -1;
        graph->distance[i] = -1;
    }
}

void BFS(struct graph* graph, int from)
{
    struct queue* queue = createQueue();
    enqueue(&queue, from);
    //inicializando os dados do nó de origem
    graph->distance[from] = 0;
    graph->visited[from] = true;
    graph->predecessor[from] = -1;

    struct node* child ;

    while(!isEmpty(queue))
    {
        child = graph->adjacencyList[queue->head->item];
        printf("Iniciando busca em largura a partir de %d\n", queue->head->item);

        while(child != NULL)
        {
            //se o nó não foi visitado
            if(!graph->visited[child->item])
            {
                enqueue(&queue, child->item);
                graph->visited[child->item] = true;
                graph->distance[child->item] = graph->distance[queue->head->item]+1;
                graph->predecessor[child->item] = queue->head->item;
            }
            child = child->next;
        }

        dequeue(&queue);
    }
}

//a partir de um array de predecessores, traça o caminho partindo do destino até a origem
void path(struct graph* graph, int to, int from, int* flag, int originalto)
{
    if(to == -1)
        return;

    if(to == from)
    {
        printf("\nCaminho entre %d e %d: ", from, originalto);
        printf("%d", to);
        *flag = 1;
        return;
    }

    path(graph, graph->predecessor[to], from, flag, originalto);
    
    if(*flag)
        printf(" => %d", to);
}