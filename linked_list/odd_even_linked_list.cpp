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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_head, *even_head;
        ListNode *odd, *even;
        int parity = 1;

        odd_head = new ListNode();
        even_head = new ListNode();
        odd = odd_head, even = even_head;

        while(head != nullptr)
        {
            if (parity)
                odd->next = head, odd = odd->next;
            else
                even->next = head, even = even->next;

            head = head->next;
            parity ^= 1;
        }

        odd->next = even_head->next;
        even->next = nullptr;

        return odd_head->next;
    }
};
