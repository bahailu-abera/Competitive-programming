#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10007

typedef struct node {
    int key;
    int val;
    struct node* next;
} node_t;

node_t* create_node(int key, int val) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->key = key;
    node->val = val;
    node->next = NULL;
    return node;
}

void insert(node_t** table, int key, int val) {
    int idx = abs(key) % TABLE_SIZE;
    if (table[idx] == NULL) {
        table[idx] = create_node(key, val);
        return;
    }
    node_t* cur = table[idx];
    while (cur != NULL) {
        if (cur->key == key) {
            cur->val += val;
            return;
        }
        cur = cur->next;
    }
    node_t* node = create_node(key, val);
    node->next = table[idx];
    table[idx] = node;
}

int lookup(node_t** table, int key) {
    int idx = abs(key) % TABLE_SIZE;
    node_t* cur = table[idx];
    while (cur != NULL) {
        if (cur->key == key) {
            return cur->val;
        }
        cur = cur->next;
    }
    return 0;
}

void free_table(node_t** table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        node_t* cur = table[i];
        while (cur != NULL) {
            node_t* tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
}

int subarraySum(int* nums, int numsSize, int k) {
    int sum = 0, count = 0;
    node_t** table = (node_t**) calloc(TABLE_SIZE, sizeof(node_t*));

    insert(table, 0, 1);
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        int diff = sum - k;
        count += lookup(table, diff);
        insert(table, sum, 1);
    }
    free_table(table);
    return count;
}
