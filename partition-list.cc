// https://oj.leetcode.com/problems/partition-list/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		ListNode *a, *b, *a_tail, *b_tail;

		a = b = a_tail = b_tail = NULL;

		while(head != NULL) {
			if (head->val < x) {
				if (a == NULL) {
					a = head;
				} else {
					a_tail->next = head;
				}
				a_tail = head;
			} else {
				if (b == NULL) {
					b = head;
				} else {
					b_tail->next = head;
				}
				b_tail = head;
			}
			head = head->next;
		}

		if (b_tail != NULL) { b_tail->next = NULL; }
		if (a == NULL) { return b; }
		a_tail->next = b;
		return a;
	}
};
