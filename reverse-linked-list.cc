// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
#if 1 //iterative
        ListNode *p = head;

        head = nullptr;
        while (p) {
            ListNode *next = p->next;

            p->next = head;
            head = p;
            p = next;
        }
        return head;
#else //recursive
        if (!head || !head->next)
            return head;

        ListNode *new_tail = head->next;
        ListNode *new_head = reverseList(head->next);
        new_tail->next = head;
        head->next = nullptr;
        return new_head;
#endif
    }
};
