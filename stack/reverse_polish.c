#include <string.h>

typedef struct stack_s {
    int long long n;
    struct stack_s *next;       
} stack_t;

int long long pop(stack_t **head);
void push(stack_t **head, int long long value);

int evalRPN(char ** tokens, int tokensSize){
    int i;
    stack_t *list = NULL;

    for (i = 0; i < tokensSize; i++)
    {
        if (strcmp(*(tokens + i), "+") == 0)
        {
            push(&list, pop(&list) + pop(&list));
        }
        else if (strcmp(*(tokens + i), "-") == 0)
        {
            push(&list, -pop(&list) + pop(&list));
        }
        else if (strcmp(*(tokens + i), "*") == 0)
        {
            push(&list, pop(&list) * pop(&list));
        }
        else if (strcmp(*(tokens + i), "/") == 0)
        {
            push(&list, pop(&list) / pop(&list));
        }
        else
        {
            push(&list, atoll(*(tokens + i)));
        }
    }

    return (pop(&list));
}

int long long pop(stack_t **head)
{
    stack_t *top;
    int  long long res;
    
    top = (*head);
    (*head) = top->next;
    res = top->n;
    free(top);

    return (res);

}

void push(stack_t **head, int long long value)
{
    stack_t *new;

    new = malloc(sizeof(stack_t));
    if (!new)
        return;
    new->n = value;
    new->next = (*head);
    (*head) = new;
}
