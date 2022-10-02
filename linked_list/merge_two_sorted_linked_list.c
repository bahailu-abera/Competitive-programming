/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *result, *new, *head;

    if (list1 == NULL)
        return (list2);
    if (list2 == NULL)
        return (list1);
    result = NULL;
    while (list1 != NULL && list2 != NULL)
    {
        new = malloc(sizeof(struct ListNode));
        if (new == NULL)
            return (NULL);
        if (list1->val <= list2->val)
        {
            new->val = list1->val;
            new->next = NULL;
            list1 = list1->next;
        }
        else
        {
            new->val = list2->val;
            new->next = NULL;
            list2 = list2->next;
        }
        if (result == NULL)
            result = new, head = result;
        else
            result->next = new, result = result->next;
    }
    while (list1 != NULL)
    {
        new = malloc(sizeof(struct ListNode));
        if (new == NULL)
            return (NULL);
        new->val = list1->val;
        new->next = NULL;
        list1 = list1->next;
        result->next = new, result = result->next;
    }
    while (list2 != NULL)
    {
        new = malloc(sizeof(struct ListNode));
        if (new == NULL)
            return (NULL);
        new->val = list2->val;
        new->next = NULL;
        list2 = list2->next;
        result->next = new, result = result->next;
    }
    return (head);
    
}
