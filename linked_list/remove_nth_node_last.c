/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *first, *target;
    int i = 0;

    first = target = head;
    while (first != NULL)
    {
        first = first->next;
        if (i > n)
            target = target->next;
        i += 1;
    }
    
    if (i == n)
    {
        first = head;
        head = head->next;
    }
    else
    {
        first = target->next;
        target->next = target->next->next;
    }
    free(first);
    return (head);
}
