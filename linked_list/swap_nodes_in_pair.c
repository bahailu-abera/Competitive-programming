/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *newHead, *remainHead;
    if (head == NULL || head->next == NULL)
        return (head);

    remainHead = head->next->next;
    newHead = head->next;
    newHead->next = head;
    head->next = swapPairs(remainHead);

    return (newHead);
}
