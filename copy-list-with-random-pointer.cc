// https://oj.leetcode.com/problems/copy-list-with-random-pointer/

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) {
			return NULL;
		}

		RandomListNode *p;

		for (p = head; p; ) {
			RandomListNode *node = new RandomListNode(p->label);
			node->next = p->next;
			p->next = node;
			p = node->next;
		}

		for (p = head; p; p = p->next->next) {
			if (p->random) {
				p->next->random = p->random->next;
			}
		}

		RandomListNode *res = head->next;
		RandomListNode *prev = NULL;

		for (p = head; p; p = p->next) {
			RandomListNode *q = p->next;
			p->next = q->next;
			if (prev) {
				prev->next = q;
			}

			prev = q;
		}

		return res;
	}
};
