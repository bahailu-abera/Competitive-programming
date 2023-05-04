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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode();
        ListNode *tail = head;

        auto comp = [](ListNode* m, ListNode* n) -> bool {
            return m->val > n->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> min_heap(comp);

        for (auto list: lists)
        {
            if (list != nullptr)
                min_heap.push(list);
        }

        while (!min_heap.empty())
        {
            ListNode *current = min_heap.top();
            min_heap.pop();
            tail->next = current;

            if (!min_heap.empty())
            {
                while (current->next != nullptr && current->next->val <= min_heap.top()->val)
                    current = current->next, tail = tail->next;
            }

            if (current->next != nullptr) min_heap.push(current->next);
            tail = tail->next;
        }

        return head->next;
    }
};
