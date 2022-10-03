/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    short sum, lft = 0;
    struct ListNode *result, *head, *new;

    result = NULL;
    while (l1 != NULL && l2 != NULL)
    {
        sum = l1->val + l2->val + lft;
        lft= sum / 10;
        new = malloc(sizeof(struct ListNode));
        if (new == NULL)
            return (NULL);
        new->val = sum % 10;
        new->next = NULL;
        if (result == NULL)
            result = new, head = result;
        else
            result->next = new, result = result->next;
        l1 = l1->next;
        l2 = l2->next;

    }
    while (l1 != NULL)
    {
        sum = l1->val + lft;
        lft= sum / 10;
        new = malloc(sizeof(struct ListNode));
        if (new == NULL)
            return (NULL);
        new->val = sum % 10;
        new->next = NULL;
        result->next = new, result = result->next;
        l1 = l1->next;
    }
     while (l2 != NULL)
    {
        sum = l2->val + lft;
        lft= sum / 10;
        new = malloc(sizeof(struct ListNode));
        if (new == NULL)
            return (NULL);
        new->val = sum % 10;
        new->next = NULL;
        result->next = new, result = result->next;
        l2 = l2->next;
    }
    if (lft != 0)
    {
        new = malloc(sizeof(struct ListNode));
        if (new == NULL)
            return (NULL);
        new->val = lft;
        new->next = NULL;
        result->next = new, result = result->next;
    }
    return (head);
}
