// https://oj.leetcode.com/problems/reorder-list/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	ListNode *middleNode(ListNode *head) {
		if (head == NULL) return NULL;
		ListNode *fast = head, *slow = head;

		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}

		return slow;
	}

	ListNode *reverse(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}

		ListNode *p = head->next;
		head->next = NULL;

		while (p) {
			ListNode *next = p->next;
			p->next = head;
			head = p;
			p = next;
		}

		return head;
	}

	void reorderList(ListNode *head) {
		// 先将链表从中间断开分为两个链表
		// 将后半部分翻转
		// 然后将两个链表合并

		if (head == NULL || head->next == NULL) return;
		ListNode *mid = middleNode(head);
		ListNode *first = head;
		ListNode *second = mid->next;

		mid->next = NULL;
		second = reverse(second);
		// 1 2
		// 3 4
		//
		// 1 2
		// |/|
		// 3 5

		while (first && second) {
			ListNode *next1 = first->next;
			ListNode *next2 = second->next;

			first->next = second;
			second->next = next1;

			first = next1;
			second = next2;
		}
	}
};
