// https://oj.leetcode.com/problems/swap-nodes-in-pairs/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode *res = head->next;
		ListNode *prev = NULL;
		ListNode *p = head;

		while (p && p->next) {
			ListNode *q = p->next;
			ListNode *next = q->next;

			if (prev) {
				prev->next = q;
			}

			q->next = p;
			p->next = next;
			prev = p;
			p = next;
		}

		return res;
	}
};

int main(int argc, char const* argv[])
{
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	ListNode *d = new ListNode(4);

	a->next = b;
	b->next = c;
	c->next = d;
	Solution s;
	ListNode *h = s.swapPairs(a);

	while (h) {
		cout << h->val << " ";
		h = h->next;
	}
	cout << endl;
	return 0;
}
