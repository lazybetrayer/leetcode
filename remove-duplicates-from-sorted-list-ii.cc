// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) { return head; }

		ListNode *new_head = NULL;
		ListNode *new_tail = NULL;
		ListNode *p = head;

		while (p != NULL) {
			ListNode *q = p->next;
			while (q != NULL && q->val == p->val) {
				ListNode *next = q->next;
				delete q;
				q = next;
			}

			if (p->next == q) {
				// no duplicates, add to new list
				if (new_head == NULL) {
					new_head = p;
				} else {
					new_tail->next = p;
				}
				new_tail = p;
			} else {
				// find duplicates
				delete p;
			}
			p = q;
		}

		if (new_tail != NULL) {
			new_tail->next = NULL;
		}

		return new_head;
	}
};
