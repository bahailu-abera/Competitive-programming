struct ListNode* adder(struct ListNode* l1, struct ListNode* l2, int carry)
{
    if (!l1 && !l2)
    {
        if (carry)
        {
            struct ListNode* node = malloc(sizeof(struct ListNode));
            node->val = carry;
            node->next = NULL;
            return node;
        }
        return NULL;
    }

    int result = carry;
    if (l1) result += l1->val, l1 = l1->next;
    if (l2) result += l2->val, l2 = l2->next;

    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = result % 10;
    node->next = adder(l1, l2, result / 10);
    return node;
}
