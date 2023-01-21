/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *prev, *cur, *tmp;
    struct ListNode *node;
    int value;

    if (head == NULL)
        return (head);
    node = NULL;
    prev = head;
    cur = head->next;
    for (; cur != NULL; )
    {
        if (prev->val == cur->val)
        {
            value = prev->val;
            while (prev->val == value)
            {
                free(prev);
                prev = cur;
                if (cur == NULL)
                    break;
                cur = cur->next;
            }

            if (node == NULL)
            {
                head = prev, node = NULL;
            }
            else
                node->next = prev;
        }
        else
            node = prev, prev = cur, cur = cur->next;
    }
    return (head);
}
