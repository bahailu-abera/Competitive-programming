typedef struct stack {
    int price;
    struct stack *next;
    int span;
} stack_t;

int pop(stack_t **stack, int *span)
{
    stack_t *node;
    int price;

    if (!*stack)
        return (-1);
    node = *stack;
    *stack = (*stack)->next;
    price = node->price;
    *span = node->span;
    free(node);
    return (price);
}

void push(stack_t **stack, int price, int span)
{
    stack_t *new = malloc(sizeof(stack_t));
    new->next = *stack;
    new->price = price;
    new->span = span;
    *stack = new;
}

void delete(stack_t *stack)
{
    stack_t *node;

    while (stack)
    {
        node = stack;
        stack = stack->next;
        free(node);
    }
}

typedef struct {
    stack_t *stack;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner *obj = malloc(sizeof(StockSpanner));
    obj->stack = NULL;

    return (obj);
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int top_span = 0, span = 1;

    while (obj->stack && obj->stack->price <= price)
        pop(&obj->stack, &top_span), span += top_span;

    push(&obj->stack, price, span);

    return (span);
}

void stockSpannerFree(StockSpanner* obj) {
    delete(obj->stack);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 * stockSpannerFree(obj);
*/
