/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct stack {
     int data;
     int index;
     struct stack *next;
 } stack_t;


void push(stack_t **head, int data, int index)
{
    stack_t *new = malloc(sizeof(stack_t));
    new->data = data;
    new->index = index;
    new->next = (*head);
    (*head) = new;
}

int pop(stack_t **head)
{
    stack_t *node;
    int index;

    node = (*head);
    (*head) = node->next;

    index = node->index;
    free(node);

    return (index);
}

int top(stack_t *head)
{
    return (head->data);
}

void delete(stack_t *head)
{
    stack_t *node;

    while (head)
    {
        node = head;
        head = node->next;
        free(node);
    }
}

int* nextLargerNodes(struct ListNode* head, int* returnSize){
    int len, index, top_index;
    int *answer;
    struct ListNode *ptr;
    stack_t *stack = NULL;

    for (len = 0, ptr = head; ptr != NULL; ptr = ptr->next, len++)
        ;
    answer = malloc(len * sizeof(int));
    for (index = 0; index < len; index++)
        answer[index] = 0;

    ptr = head;
    index = top_index = 0;

    for (; ptr != NULL; ptr = ptr->next)
    {
        if (stack == NULL)
            push(&stack, ptr->val, index), index++;
        else
        {
            while (stack != NULL && top(stack) < ptr->val)
            {
                top_index = pop(&stack);
                answer[top_index] = ptr->val;
            }
            push(&stack, ptr->val, index);
            index++;
        }

    }
    delete(stack);
    *returnSize = len;

    return (answer);
}
