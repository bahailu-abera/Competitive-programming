typedef struct list
{
    int data;
    struct list *next;
} list_t ;


void push(list_t **head, int value)
{
    list_t *new = malloc(sizeof(list_t));
    new->data = value;
    new->next = (*head);

    (*head) = new;
}
void delete_list(list_t *head)
{
    list_t *node;

    while (head)
    {
        node = head;
        head = head->next;
        free(node);
    }
}

typedef struct graph
{
    list_t **list;
} graph_t;

void delete_graph(graph_t *graph, int edge_size)
{
    for (int i = 0; i < edge_size; i++)
        delete_list(graph->list[i]);

    free(graph);
}

graph_t *build_graph(graph_t *graph, int **matrix, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (matrix[i][j] == 1)
            {
                push(&(graph->list[i]), j);
                push(&(graph->list[j]), i);
            }
        }
    }

    return graph;
}

void dfs(graph_t *graph, int current, int *visited)
{
    list_t *node = graph->list[current];

    visited[current] = 1;
    while (node)
    {
       if (visited[node->data] == 0)
        {
            dfs(graph, node->data, visited);
        }
        node = node->next;
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    graph_t *graph = malloc(sizeof(graph_t));

    graph->list = malloc(isConnectedSize * sizeof(list_t));
    for (int i = 0; i < isConnectedSize; i++)
    {
        graph->list[i] = NULL;
    }

    build_graph(graph, isConnected, isConnectedSize);
    int *visited = calloc(isConnectedSize, sizeof(int));
    int count = 0;

    for (int i = 0; i < isConnectedSize; i++)
    {
        if (visited[i] == 0)
            dfs(graph, i, visited), count++;
    }

    delete_graph(graph, isConnectedSize);

    return count;
}
