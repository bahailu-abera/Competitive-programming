#include <stdlib.h>

typedef struct {
    int long minElement;
    int size;
    int long *array;
    int top;
} MinStack;


MinStack* minStackCreate() {
    MinStack *obj = malloc(sizeof(MinStack));
    obj->size = 4;
    obj->top = -1;
    obj->array = malloc(sizeof(int long) * 4);
    return (obj);
}

void minStackPush(MinStack* obj, int val) {
    int long *array, i, size;
    int long tmp;
    
    tmp = (int long)val;
    if (obj->top == -1)
    {
        (obj->top)++;
        obj->array[obj->top] = tmp;
        obj->minElement = tmp;
    }
    else
    {

    if (val < obj->minElement)
    {
       tmp = (2 * tmp) - obj->minElement;
       obj->minElement = (int long)val;
    }
    if (obj->top == obj->size - 1)
    {
        size = obj->size * 2;
        array = malloc(sizeof(int long) * size);
        for (i = 0; i < obj->size; i++)
        {
            array[i] = (obj->array)[i];
        }
        obj->top++;
        obj->array = (void *)array;
        obj->array[obj->top] = tmp;
        obj->size = size;

    }
    else
    {
        obj->top++;
        obj->array[obj->top] = tmp;
    }
    }
}

void minStackPop(MinStack* obj) {
    int long top = obj->array[obj->top];

    if (top < obj->minElement)
    {
        top = (2 * obj->minElement);
        top -= obj->array[obj->top];
        obj->minElement = top;
    }
    (obj->top)--;
}

int minStackTop(MinStack* obj) {
    if (obj->array[obj->top] < obj->minElement)
        return ((int)obj->minElement);
    return ((int)obj->array[obj->top]);
}

int minStackGetMin(MinStack* obj) {
    return (obj->minElement);
}

void minStackFree(MinStack* obj) {
    free(obj->array);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
