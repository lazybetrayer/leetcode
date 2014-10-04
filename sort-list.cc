#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *middleNode(ListNode *head) {
	if (head == NULL) return NULL;

	ListNode *fast = head, *slow = head;

	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

ListNode *merge(ListNode *a, ListNode *b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	ListNode *head = NULL, *tail = NULL;

	while (a && b) {
		ListNode **p;
		if (a->val <= b->val) {
			p = &a;
		} else {
			p = &b;
		}

		if (head == NULL) {
			head = *p;
		} else {
			tail->next = *p;
		}
		tail = *p;
		*p = (*p)->next;
	}

	if (a) tail->next = a;
	if (b) tail->next = b;
	return head;
}

// merge sort
ListNode *sortList(ListNode *head) {
	if (head == NULL || head->next == NULL) return head; // 防止只有一个节点时死循环

	ListNode *mid = middleNode(head);
	ListNode *first = head;
	ListNode *second = mid->next;

	mid->next = NULL;
	first = sortList(first);
	second = sortList(second);

	return merge(first, second);
}
