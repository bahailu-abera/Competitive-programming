#include <stdlib.h>
#include <string.h>

typedef struct list
{
    int data;
    struct list *next;
} list_t;

void push(list_t **head, int data)
{
    list_t *new = malloc(sizeof(list_t));
    if (new == NULL)
        return;
    new->data = data;
    new->next = *head;
    (*head) = new;
}

int pop(list_t **head)
{
    list_t *node;
    int data;

    node = *head;
    (*head) = (*head)->next;
    data = node->data;
    free(node);

    return (data);
}

void delete(list_t *head)
{
    list_t *node;

    while (head)
        node = head, head = head->next, free(node);
}

int evalRPN(char ** tokens, int tokensSize){
    list_t *stack = NULL;
    int i, operand1, operand2;

    for (i = 0; i < tokensSize; i++)
    {
        if (strcmp(tokens[i], "+") == 0)
        {
            operand1 = pop(&stack);
            operand2 = pop(&stack);
            push(&stack, operand2 + operand1);
        }
        else if (strcmp(tokens[i], "-") == 0)
        {
            operand1 = pop(&stack);
            operand2 = pop(&stack);
            push(&stack, operand2 - operand1);
        }
        else if (strcmp(tokens[i], "*") == 0)
        {
            operand1 = pop(&stack);
            operand2 = pop(&stack);
            push(&stack, operand2 * operand1);
        }
        else if (strcmp(tokens[i], "/") == 0)
        {
            operand1 = pop(&stack);
            operand2 = pop(&stack);
            push(&stack, operand2 / operand1);
        }
        else
        {
            push(&stack, atoi(tokens[i]));
        }
    }
    operand1 = pop(&stack);
    delete(stack);

    return (operand1);
}
