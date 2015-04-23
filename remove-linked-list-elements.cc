// https://leetcode.com/problems/remove-linked-list-elements/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode *p = head;
		ListNode *new_head = nullptr, *new_tail = nullptr;

		while (p) {
			auto next = p->next;
			if (p->val != val) {
				if (new_tail) {
					new_tail->next = p;
				} else {
					new_head = p;
				}
				p->next = nullptr;
				new_tail = p;
			}
			p = next;
		}
		return new_head;
	}
};
