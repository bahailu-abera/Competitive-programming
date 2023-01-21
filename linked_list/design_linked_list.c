typedef struct list {
    int val;
    struct list *next;
} list_t;

typedef struct {
    int size;
    list_t *list;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = malloc(sizeof(MyLinkedList));
    obj->list = NULL;
    obj->size = 0;

    return (obj);
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    int i;
    list_t *tmp;

    if (index >= obj->size)
        return (-1);
    tmp = obj->list;

    for (i = 0; tmp != NULL; tmp = tmp->next, i++)
        if (i == index)
            break;
    return (tmp->val);
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    list_t *new = malloc(sizeof(list_t));

    new->val = val;
    new->next = obj->list;
    obj->list = new;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    list_t *new, *tmp;

    if (obj->size == 0)
       myLinkedListAddAtHead(obj, val);

    else
    {    tmp = obj->list;

        for(; tmp->next != NULL; tmp = tmp->next)
            ;
        new = malloc(sizeof(list_t));
        new->val = val;
        new->next = NULL;
        tmp->next = new;
        obj->size++;
    }
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    list_t *tmp, *new;
    int i;

    if (index == 0)
        myLinkedListAddAtHead(obj, val);
    else if (index == obj->size)
        myLinkedListAddAtTail(obj, val);
    else if (index > obj->size)
        return;
    else
    {    tmp = obj->list;

        for (i = 1; i < index; i++)
            tmp = tmp->next;
        new = malloc(sizeof(list_t));
        new->val = val;
        new->next = tmp->next;
        tmp->next = new;
        obj->size++;

    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    list_t  *cur, *prev;
    int i;

    if (index >= obj->size)
        return;
    prev = NULL;
    cur = obj->list;

    for (i = 0; cur != NULL; prev = cur, cur = cur->next, i++)
        if (i == index)
            break;
    // remove head
    if (prev == NULL)
        obj->list = obj->list->next, free(cur);
    else
        prev->next = cur->next, free(cur);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    list_t *node, *tmp;

    node = obj->list;

    while (node)
    {
        tmp = node;
        node = node->next;
        free(tmp);
    }

    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/
