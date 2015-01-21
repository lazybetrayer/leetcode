// https://oj.leetcode.com/problems/intersection-of-two-linked-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
#if 1
		ListNode *p = headA, *q = headB;

		if (p == NULL || q == NULL) return NULL;

		while (p != NULL && q != NULL && p != q) {
			p = p->next;
			q = q->next;

			// 如果没有交点，最后p，q都为NULL
			//
			// Any time they collide or reach end together without colliding
			// then return any one of the pointers.
			//
			if (p == q) return p;

			//
			// If one of them reaches the end earlier then reuse it
			// by moving it to the beginning of other list.
			// Once both of them go through reassigning,
			// they will be equidistant from the collision point.
			//
			if (p == NULL) p = headB;
			if (q == NULL) q = headA;
		}

		return p;
#else
#if 1
		if (!headA || !headB) return NULL;

		ListNode *pa = headA, *pb = headB;
		ListNode *a_tail = NULL, *b_tail = NULL;

		while (pa != pb) {
			if (pa->next) {
				pa = pa->next;
			} else {
				a_tail = pa;
				pa = headB;
			}

			if (pb->next) {
				pb = pb->next;
			} else {
				b_tail = pb;
				pb = headA;
			}

			if (a_tail && b_tail && a_tail != b_tail) {
				return NULL;
			}
		}

		return pa;
#else
		if (headA == NULL || headB == NULL) {
			return NULL;
		}

		int alen = 1, blen = 1;
		ListNode *p = headA, *q = headB;

		while (p->next) {
			alen++;
			p = p->next;
		}

		while (q->next) {
			blen++;
			q = q->next;
		}

		if (p != q) {
			return NULL;
		}

		if (alen < blen) {
			swap(headA, headB);
			swap(alen, blen);
		}

		for (int i = 0; i < alen - blen; i++) {
			headA = headA->next;
		}

		while (headA != headB) {
			headA = headA->next;
			headB = headB->next;
		}

		return headA;
#endif
#endif
	}
};
