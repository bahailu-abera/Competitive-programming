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
    int pairSum(ListNode* head) {
        int max_sum = 0;
       stack<int> S;
       ListNode *tmp = head;

       while (tmp) S.push(tmp->val), tmp = tmp->next;

       while (!S.empty())
       {
           int current = S.top() + head->val;
           if (current > max_sum)
                max_sum = current;

            S.pop();
            head = head->next;
       }

       return (max_sum);
    }
};
