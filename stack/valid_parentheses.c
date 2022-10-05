int close(int open)
{
    if (open == '(')
        return (')');
    else if (open == '{')
        return ('}');
    else
        return (']');
}
bool isValid(char * s){
    typedef struct listchar_s {
        char b;
        struct listchar_s *next;
    } listchar_t;

    listchar_t *new, *head;
    head = NULL;
    while (*s != '\0')
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {
            new = malloc(sizeof(listchar_t));
            if (new == NULL)
                return (NULL);
            new->b = *s;
            new->next = NULL;
            new->next = head;
            head = new;
        }
        else
        {
            if (head == NULL)
                return (false);
            if (close(head->b) != *s)
                return (false);
            listchar_t *node = head->next;
            free(head);
            head = node;
        }
        s += 1;
    }
    if (head == NULL)
        return (true);
    return (false);

}
