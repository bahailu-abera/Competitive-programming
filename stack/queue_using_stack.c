typedef struct stack_s 
{
    int n;
    struct stack_s *next;
} stack_t;

typedef struct{
    stack_t *stack1;
    stack_t *stack2;
} MyQueue;

/* function prototypes */
void push(stack_t **head, int x);
int pop(stack_t **head);
int peek(stack_t *head);
void free_list(stack_t *head);
MyQueue* myQueueCreate();
void myQueuePush(MyQueue* node, int x);
int myQueuePop(MyQueue* node);
int myQueuePeek(MyQueue* node);
bool myQueueEmpty(MyQueue* node);
void myQueueFree(MyQueue* node);


void push(stack_t **head, int x)
{
    stack_t *new = malloc(sizeof(stack_t));
    if (new == NULL)
        return;
    new->n = x;
    new->next = (*head);
    (*head) = new;
}

int pop(stack_t **head)
{
    int res;
    stack_t *top;
    
    if (*head == NULL)
        exit(-1);
    top = (*head);
    res = top->n;
    (*head) = top->next;
    free(top);

    return (res);
}

int peek(stack_t *head)
{
    int res;

    if (head == NULL)
        exit(-1);
    
    return (head->n);
}

void free_list(stack_t *head)
{
    stack_t *node;

    if (head)
    {
        node = head->next;
        free(head);
        free(node);
    }
}

MyQueue* myQueueCreate() {
    MyQueue *queue = malloc(sizeof(MyQueue));
    if (queue == NULL)
        return (NULL);
    queue->stack1 = NULL;
    queue->stack2 = NULL;

    return (queue);
}

void myQueuePush(MyQueue* node, int x) {
   push(&node->stack1, x);
}

int myQueuePop(MyQueue* node) {
    int res;

    if (myQueueEmpty(node))
        exit(-1);
    
    if (node->stack2 == NULL)
    {
        while (node->stack1 != NULL)
        {
            res = pop(&node->stack1);
            push(&node->stack2, res);
        }
    }
    res = pop(&node->stack2);
    return (res);
}

int myQueuePeek(MyQueue* node) {
    int res;

    if (myQueueEmpty(node))
        exit(-1);
    
    if (node->stack2 == NULL)
    {
        while (node->stack1 != NULL)
        {
            res = pop(&node->stack1);
            push(&node->stack2, res);
        }
    }
    res = peek(node->stack2);
    return (res);
}

bool myQueueEmpty(MyQueue* node) {
    if (node->stack1 == NULL && node->stack2 == NULL)
        return (true);
    return (false);
}

void myQueueFree(MyQueue* node) {
    
    free_list(node->stack1);
    free_list(node->stack2);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* node = myQueueCreate();
 * myQueuePush(node, x);
 
 * int param_2 = myQueuePop(node);
 
 * int param_3 = myQueuePeek(node);
 
 * bool param_4 = myQueueEmpty(node);
 
 * myQueueFree(node);
*/
