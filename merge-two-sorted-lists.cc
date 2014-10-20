// https://oj.leetcode.com/problems/merge-two-sorted-lists/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
#if 1
		if (!l1) return l2;
		if (!l2) return l1;

		ListNode *head = NULL, *tail = NULL;

		while (l1 && l2) {
			ListNode **node = &l1;
			if (l1->val > l2->val) node = &l2;

			if (head)
				tail->next = *node;
			else
				head = *node;
			tail = *node;
			*node = (*node)->next;
		}

		if (l1) tail->next = l1;
		if (l2) tail->next = l2;
		return head;
#else
		if (!l1) return l2;
		if (!l2) return l1;

		ListNode *head;
		if (l1->val <= l2->val) {
			head = l1;
			head->next = mergeTwoLists(l1->next, l2);
		} else {
			head = l2;
			head->next = mergeTwoLists(l1, l2->next);
		}

		return head;

#endif
	}
};
