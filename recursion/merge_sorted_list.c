/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *result = NULL;

    if (!list1)
        return (list2);
    if (!list2)
        return (list1);
    if (list1->val < list2->val)
        result = list1, result->next = mergeTwoLists(list1->next, list2);
    else
        result = list2, result->next = mergeTwoLists(list2->next, list1);

    return result;
}
