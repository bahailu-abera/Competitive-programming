/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* prev, *cur, *l;
    struct ListNode* newHead;
    int count = 1;
    
    if (head == NULL || head->next == NULL)
        return (head);
    
    l = head;
    while (++count < left)
        l = l->next;

    ((count > left) ? (newHead = head, count--): (newHead = l->next));
    prev = newHead;

    while (count++ < right && (cur = prev->next))
    {
        prev->next = cur->next;
        cur->next = newHead;
        newHead = cur;
    }
    if (left == 1)
        return newHead;
    l->next = newHead;
    return (head);
}
