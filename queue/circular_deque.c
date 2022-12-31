typedef struct {
    int front;
    int rear;
    int *arr;
    int size;
} MyCircularDeque;
// function prototypes
MyCircularDeque* myCircularDequeCreate(int k);
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value);
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value);
bool myCircularDequeDeleteFront(MyCircularDeque* obj);
bool myCircularDequeDeleteLast(MyCircularDeque* obj);
int myCircularDequeGetFront(MyCircularDeque* obj);
int myCircularDequeGetRear(MyCircularDeque* obj);
bool myCircularDequeIsEmpty(MyCircularDeque* obj);
bool myCircularDequeIsFull(MyCircularDeque* obj);
void myCircularDequeFree(MyCircularDeque* obj);

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *deque = malloc(sizeof(MyCircularDeque));

    if (deque == NULL)
    {
        fprintf(stderr, "Malloc Failed\n");
        exit(1);
    }
    deque->arr = malloc(k * sizeof(int));
    deque->size = k;
    deque->front = -1;
    deque->rear = -1;

    return (deque);
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj))
    {
        return (false);
    }
    if (obj->front == -1)
    {
        obj->front = obj->rear = 0;
        obj->arr[obj->front] = value;
        return (true);
    }
    if (obj->front == 0)
    {
        obj->front = obj->size - 1;
        obj->arr[obj->front] = value;
        return (true);
    }
    obj->front--;
    obj->arr[obj->front] = value;
    return (true);
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj))
    {
        return (false);
    }
    if (obj->front == -1)
    {
        obj->front = obj->rear = 0;
        obj->arr[obj->rear] = value;
        return (true);
    }
    obj->rear = (obj->rear + 1) % obj->size;
    obj->arr[obj->rear] = value;
    return (true);
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
    {
        return (false);
    }
    if (obj->front == obj->rear)
    {
        obj->front = obj->rear = -1;
        return (true);
    }
    obj->front = (obj->front + 1) % obj->size;
    return (true);
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
    {
        return (false);
    }
    if (obj->front == obj->rear)
    {
        obj->front = obj->rear = -1;
        return (true);
    }
    obj->rear--;
    if (obj->rear < 0)
        obj->rear = obj->size - 1;
    return (true);
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
   if (myCircularDequeIsEmpty(obj))
    {
        return (-1);
    }
    return (obj->arr[obj->front]);
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
    {
        return (-1);
    }
    return (obj->arr[obj->rear]);
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if (obj->front == -1)
        return (true);
    return (false);
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if (obj->front == 0 && obj->rear == obj->size - 1)
        return (true);
    if (obj->front == obj->rear + 1)
        return (true);
    return (false);
}

void myCircularDequeFree(MyCircularDeque* obj) {
    if (obj)
    {
        free(obj->arr);
        free(obj);
    }
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
