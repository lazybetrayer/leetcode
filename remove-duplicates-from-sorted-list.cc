// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) { return head; }

		ListNode *p = head;
		ListNode *q = head->next;

		while (q != NULL) {
			ListNode *next = q->next;

			if (q->val != p->val) {
				p->next = q;
				p = q;
			} else {
				delete q;
			}
			q = next;
		}
		p->next = NULL;

		return head;
	}
};
