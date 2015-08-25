// https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *p = head;
        ListNode *q = nullptr; // tail of the first part
        int i = 1;

        for (; i < m; i++) {
            q = p;
            p = p->next;
        }

        // reverse
        ListNode *sub_head = nullptr;
        ListNode *sub_tail = p;
        for (; i <= n; i++) {
            ListNode *next = p->next;
            p->next = sub_head;
            sub_head = p;
            p = next;
        }

        sub_tail->next = p;

        if (q) {
            q->next = sub_head;
        } else {
            head = sub_head;
        }

        return head;
    }
};
