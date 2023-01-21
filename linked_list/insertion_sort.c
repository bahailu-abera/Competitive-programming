/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode *cur, *sorted, *tmp, *curNext, *prev;

    sorted = head, cur = head->next;
    sorted->next = NULL;

    while (cur != NULL)
    {
        tmp = sorted;
        curNext = cur->next;
        prev = NULL;
        while (tmp != NULL && cur->val > tmp->val)
        {
            prev = tmp;
            tmp = tmp->next;
        }
        cur->next = tmp;
        if (prev == NULL)
            sorted = cur;
        else
            prev->next = cur;
        cur = curNext;
    }
    return (sorted);
}
