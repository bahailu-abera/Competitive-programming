/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;

        slow = fast = head;
        while (1)
        {
            if (fast == nullptr || fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast)
                break;
        }

        slow = head;
        while (1)
        {
            if (fast == slow)
                break;
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
