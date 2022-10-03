/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *prev, *cur;

    if (head == NULL)
        return (NULL);
    prev = head;
    cur = prev->next;
    while(cur != NULL)
    {
        if (cur->val == prev->val)
        {
            prev->next = cur->next;
            free(cur);
            cur = prev->next;

        }
        else
            prev = cur, cur = cur->next;
    }
    
    return (head);

}
