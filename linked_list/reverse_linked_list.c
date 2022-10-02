/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *cur, *prev;

    if (head == NULL)
        return (NULL);
    prev = head;
    while ((cur = prev->next))
    {
        prev->next = cur->next;
        cur->next = head;
        head = cur;
    }
    return (head);
}
