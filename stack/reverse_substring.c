#include <stdlib.h>

typedef struct stack_s {
    int *arr;
    int top;
    int size;
} stack_t;

typedef struct dict_s {
    int *arr;
    int size;
} dict_t;

stack_t *create_stack()
{
    stack_t *stack = malloc(sizeof(stack_t));
    stack->size = 2;
    stack->arr = malloc(sizeof(int) * 2);
    stack->top = -1;

    return (stack);
}
void push(stack_t *stack, int value)
{
    int *array, i, size;
    
    if (stack->top < stack->size - 1)
    {
        stack->top++;
        stack->arr[stack->top] = value;
    }
    else
    {
        size = stack->size * 2;
        array = malloc(sizeof(int) * size);
        for (i = 0; i < stack->size; i++)
        {
            array[i] = (stack->arr)[i];
        }
        stack->arr = (void *)array;
        stack->top++;
        (stack->arr)[stack->top] = value;
        stack->size = size;
    }
}

int pop(stack_t *stack)
{
    int res = (stack->arr)[stack->top];
    stack->top--;

    return (res);
}

dict_t *create_dict()
{
    dict_t *dict = malloc(sizeof(dict_t));
    dict->arr = malloc(sizeof(int) * 8);
    dict->size = 8;

    return (dict);
}
int get(dict_t *dict, int index)
{
    int res = (dict->arr)[index];

    return (res);
}

void set(dict_t *dict, int open, int close)
{
    int *array, i, size;
    if (close < dict->size - 1)
    {
        (dict->arr)[open] = close;
        (dict->arr)[close] = open;
    }
    else
    {
        size = close + 4;
        array = malloc(sizeof(int) * size);
        
        for (i = 0; i < dict->size; i++)
        {
            array[i] = (dict->arr)[i];
        }
        dict->arr = (void *)array;
        (dict->arr)[open] = close;
        (dict->arr)[close] = open;
        dict->size = size;
    }
}

char * reverseParentheses(char * s){
    int i = 0, len = 0, d, j;
    char *res;
    stack_t *stack = create_stack();
    dict_t *dict = create_dict();

    while (*(s + i) != '\0')
    {
        if (*(s + i) == '(')
        {
            push(stack, i);
        }
        else if (*(s + i) == ')')
        {
            set(dict, pop(stack), i);
        }
        else
            len++;
        i++;
    }
    res = malloc(sizeof(char) * (len + 1));

    for (i = 0, j = 0, d = 1; *(s + i) != 0; i += d)
    {
        if (*(s + i) == '(' || *(s + i) == ')')
        {
            i = get(dict, i), d = -d;
        }
        else
            *(res + j) = *(s + i), j++;
    }
    *(res + j) = '\0';

    return (res);

}
