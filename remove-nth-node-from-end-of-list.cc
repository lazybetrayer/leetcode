// https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *fast = head;
		ListNode *slow = head;
		ListNode *prev = NULL;

		for (int i = 0; i < n && fast; i++) {
			fast = fast->next;
		}

		while (fast) {
			fast = fast->next;
			prev = slow;
			slow = slow->next;
		}

		if (!prev) {
			// 删除的是头结点
			delete head;
			head = head->next;
		} else {
			prev->next = slow->next;
			delete slow;
		}

		return head;
	}
};
