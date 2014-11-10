// https://oj.leetcode.com/problems/merge-k-sorted-lists/

#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// http://www.cnblogs.com/TenosDoIt/p/3673188.html
class Solution {
public:
#if 1
	ListNode *merge2Lists(ListNode *a, ListNode *b) {
		ListNode *head = NULL, *tail = NULL;

		if (!a) return b;
		if (!b) return a;

		while (a && b) {
			ListNode *p;
			if (a->val <= b->val) {
				p = a;
				a = a->next;
			} else {
				p = b;
				b = b->next;
			}

			if (head == NULL) {
				head = p;
			} else {
				tail->next = p;
			}
			tail = p;
		}

		if (a) { tail->next = a; }
		if (b) { tail->next = b; }

		return head;
	}
#if 1
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if (lists.empty()) return NULL;
		int n = lists.size();

		// non recursive version
		for (int k = 1; k < n; k *= 2) {
			for (int i = 0; i < n-k; i += k*2) {
				lists[i] = merge2Lists(lists[i], lists[i+k]);
			}
		}

		return lists[0];
	}
#else
	ListNode *mergeKLists(vector<ListNode *> &lists, int start, int end) {
		if (start > end) {
			return NULL;
		} else if (start == end) {
			return lists[start];
		}

		int mid = start + (end-start)/2;
		ListNode *a = mergeKLists(lists, start, mid);
		ListNode *b = mergeKLists(lists, mid+1, end);
		return merge2Lists(a, b);
	}
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		return mergeKLists(lists, 0, static_cast<int>(lists.size())-1);
	}
#endif
#else
#if 1
	struct Compare {
		bool operator()(ListNode *a, ListNode *b) const {
			return a->val > b->val;
		}
	};
#if 1
	// k个list，每个list平均长度为n
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode *head = nullptr, *tail = nullptr;
		priority_queue<ListNode *, vector<ListNode *>, Compare> q;

		for (auto node : lists) {
			if (node) {
				q.push(node);
			}
		}

		// 一共有n*k个节点，循环n*k次
		// O(n*k*log(k))
		while (!q.empty()) {
			ListNode *node = q.top();
			q.pop();

			if (head == nullptr) {
				head = node;
			} else {
				tail->next = node;
			}
			tail = node;

			if (node->next) {
				q.push(node->next);
			}
		}

		return head;
	}
#else
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode *head = nullptr, *tail = nullptr;
		Compare compare;

		lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());
		make_heap(lists.begin(), lists.end(), compare);

		while (!lists.empty()) {
			pop_heap(lists.begin(), lists.end(), compare);
			ListNode *node = lists.back();
			//lists.pop_back();

			if (head == nullptr) {
				head = node;
			} else {
				tail->next = node;
			}
			tail = node;

			if (node->next) {
				lists.back() = node->next;
				//lists.push_back(node->next);
				push_heap(lists.begin(), lists.end(), compare);
			} else {
				lists.pop_back();
			}
		}

		return head;
	}
#endif
#else
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode *head = NULL, *tail = NULL;

		// O(n*k*k)
		while (true) {
			int i = -1;
			for (int j = 0; j < lists.size(); j++) {
				if (lists[j] != NULL && (i == -1 || lists[j]->val < lists[i]->val)) {
					i = j;
				}
			}
			if (i == -1) {
				break;
			}
			if (head == NULL) {
				head = lists[i];
			} else {
				tail->next = lists[i];
			}
			tail = lists[i];
			lists[i] = lists[i]->next;
		}
		return head;
	}
#endif
#endif
};

