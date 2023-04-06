#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int value;
	struct list *next;
} list_t;

typedef struct graph {
	list_t **list;
} graph_t;

void add_list(list_t **head, int v)
{
	list_t *new = malloc(sizeof(list_t));
	new->value = v;
	new->next = *head;
	(*head) = new;
}

void free_list(list_t *head)
{
	list_t *node;

	while (head)
	{
		node = head;
		head = head->next;
		free(node);
	}

}

void add_edge(graph_t *graph, int u, int v)
{
	add_list(&(graph->list[u]), v);
	add_list(&(graph->list[v]), u);
}

void vertex(graph_t *graph, int u)
{
	list_t *head = graph->list[u];

	while (head && head->next)
		printf("%d ", head->value), head = head->next;

	if (head)
		printf("%d\n", head->value);
	else
		printf("\n");
}

void delete(graph_t *graph, int size)
{
	for (int i = 0; i < size; i++)
		free_list(graph->list[i]);

	free(graph->list);
	free(graph);
}

int main(void)
{
	int vertices, operations, op = 0, u, v;
	graph_t *graph;

	scanf("%d\n", &vertices);
	scanf("%d\n", &operations);

	graph = malloc(sizeof(graph_t));
	graph->list = calloc(vertices, sizeof(list_t));
	for (int i = 0; i < vertices; i++)
		graph->list[i] = NULL;

	while (operations--)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d %d\n", &u, &v);
			add_edge(graph, u, v);
		}
		else
		{
			scanf("%d\n", &u);
			vertex(graph, u);
		}
	}

	delete(graph, vertices);

	return (0);
}
