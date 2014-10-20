// https://oj.leetcode.com/problems/add-two-numbers/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *p = l1, *q = l2;
		ListNode *head = NULL, *tail = NULL;
		int carry = 0;

		while (p != NULL || q != NULL || carry != 0) {
			int n = carry;

			if (p != NULL) { n += p->val; }
			if (q != NULL) { n += q->val; }

			carry = n / 10;
			ListNode *node = new ListNode(n % 10);
			if (head == NULL) {
				head = node;
			} else {
				tail->next = node;
			}
			tail = node;

			if (p != NULL) { p = p->next; }
			if (q != NULL) { q = q->next; }
		}

		return head;
	}
};
