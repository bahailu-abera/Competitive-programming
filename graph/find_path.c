/**
* struct list -  a list struct for linked list implementation
*
* @value: the value at the node
* @next: a pointer to the next node
*/
typedef struct list
{
    int value;
    struct list *next;
} list_t;

void push(list_t **head, int n)
{
    list_t *new = malloc(sizeof(list_t));
    new->value = n;
    new->next = (*head);
    (*head) = new;
}

void free_list(list_t *head)
{
    list_t *node;

    while (head)
    {
        node = head, head = head->next;
        free(node);
    }
}
/**
* struct graph - data structure for graph representation
*
* @list: a double pointer to list_t
*/
typedef struct graph
{
    list_t **list;
} graph_t;


void delete(graph_t *graph, int size)
{
    for (int i = 0; i < size; i++)
    {
        free_list(graph->list[i]);
    }

    free(graph);
}

graph_t *build_graph(int n, int **edges, int edgesSize)
{
    graph_t *graph = malloc(sizeof(graph_t));
    graph->list = calloc(n, sizeof(list_t));
    for (int i = 0; i < n; i++)
        graph->list[i] = NULL;

    for (int i = 0; i < edgesSize; i++)
    {
        push(&(graph->list[edges[i][0]]), edges[i][1]);
        push(&(graph->list[edges[i][1]]), edges[i][0]);
    }

    return (graph);
}

bool find_path(graph_t *graph, int *visited, int vertex, int destination)
{
    if (vertex == destination)
        return (true);

    if (visited[vertex] != 0)
        return (false);

    visited[vertex] = 1;
    list_t *neighbors = graph->list[vertex];
    while (neighbors != NULL)
    {
        if (neighbors->value == destination)
            return (true);

        if (visited[neighbors->value] == 0)
        {
            bool flag = find_path(graph, visited, neighbors->value, destination);
            if (flag)
                return (true);
        }
        neighbors = neighbors->next;
    }

    return (false);
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination){
    graph_t *graph = build_graph(n, edges, edgesSize);

    int *visited = calloc(n, sizeof(int));
    bool is_valid = find_path(graph, visited, source, destination);

    delete(graph, n);

    return (is_valid);
}
