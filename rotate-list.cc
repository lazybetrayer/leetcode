// https://oj.leetcode.com/problems/rotate-list/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// Given a list, rotate the list to the right by k places, where k is non-negative.
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

class Solution {
public:
#if 1
	// http://fisherlei.blogspot.com/2013/01/leetcode-rotate-list.html
	// 首先从head开始跑，直到最后一个节点，这时可以得出链表长度len。然后将尾指针指向头指针，将整个圈连起来，接着往前跑
	// len - k%len，从这里断开，就是要求的结果了。
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == NULL || k == 0) {
			return head;
		}

		ListNode *p = head;
		int len = 1;

		while (p->next) {
			p = p->next;
			len++;
		}

		k %= len;

		if (k == 0) {
			return head;
		}

		p->next = head;

		for (int i = 0; i < len - k; i++) {
			p = p->next;
		}

		head = p->next;
		p->next = NULL;
		return head;
	}
#else
	ListNode *reverse(ListNode *h) {
		if (h == NULL || h->next == NULL) {
			return h;
		}

		ListNode *p = h->next;
		h->next = NULL;

		while (p) {
			ListNode *next = p->next;
			p->next = h;
			h = p;
			p = next;
		}

		return h;
	}

	int listLength(ListNode *head) {
		int len = 0;

		while (head) {
			len++;
			head = head->next;
		}

		return len;
	}

	ListNode *rotateRight(ListNode *head, int k) {
		if (head == NULL || k == 0) {
			return head;
		}

		// 可以在翻转链表的时候同时计算长度
		int len = listLength(head);
		k %= len;

		if (k == 0) {
			return head;
		}

		head = reverse(head);

		ListNode *p = head;

		for (int i = 0; i < k - 1 && p != NULL; i++) {
			p = p->next;
		}

		ListNode *first = head;
		ListNode *second = p->next;
		p->next = NULL;

		first = reverse(first);
		head->next = reverse(second);

		return first;
	}
#endif
};

void print(ListNode *head) {
	while (head) {
		cout << head->val << " ";
	}
	cout << endl;
}

int main(int argc, char const* argv[])
{
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	a->next = b;

	Solution s;
	a = s.rotateRight(a, 2);
	print(a);
	return 0;
}
