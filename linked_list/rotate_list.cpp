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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *newHead, *first, *tmp;
        tmp = head;

        while (tmp) length++, tmp = tmp->next; /*find the length of the list */

        int amount = k % length;
        amount = length - amount;

        newHead = new ListNode();
        first = new ListNode();
        tmp = first;

        while (amount--)
        {
            tmp->next = new ListNode(head->val);
            head = head->next;
            tmp = tmp->next;
        }

        tmp->next = nullptr;
        tmp = newHead;
        while (head)
            tmp->next = new ListNode(head->val), tmp = tmp->next, head = head->next;

        tmp->next = first->next;

        return newHead->next;
    }
};
