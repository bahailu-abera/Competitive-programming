/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *before_head, *after_head;
        ListNode *before, *after;

        before_head = new ListNode();
        after_head = new ListNode();
        before = before_head, after = after_head;

        while (head != nullptr)
        {
            if (head->val < x)
                before->next = head, before = before->next;

            else
                after->next = head, after = after->next;
            head = head->next;
        }

        before->next = after_head->next;
        after->next = nullptr;

        return before_head->next;
    }
};
