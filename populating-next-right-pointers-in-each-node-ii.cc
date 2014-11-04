// https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
#if 1
	void connect(TreeLinkNode *root) {
		if (root == NULL) return;

		TreeLinkNode *p = root;
		root->next = NULL;

		// 层序遍历，遍历一层时把下一层的节点连接起来，并记录下一层的第一个节点
		while (p != NULL) {
			TreeLinkNode *next = NULL;
			TreeLinkNode *prev = NULL;

			while (p != NULL) {
				if (p->left != NULL) {
					if (next == NULL) {
						next = p->left;
					} else {
						prev->next = p->left;
					}
					prev = p->left;
				}
				if (p->right != NULL) {
					if (next == NULL) {
						next = p->right;
					} else {
						prev->next = p->right;
					}
					prev = p->right;
				}
				p = p->next;
			}
			p = next;
		}
	}
#else
	void connect(TreeLinkNode *root) {
		if (root == NULL) return;

		TreeLinkNode *next_level_start = NULL;
		TreeLinkNode *p = root;
		TreeLinkNode *prev = NULL;
		root->next = NULL;

		while (p != NULL) {
			if (p->left != NULL) {
				if (prev != NULL) {
					prev->next = p->left;
				} else {
					next_level_start = p->left;
				}
				prev = p->left;
			}

			if (p->right != NULL) {
				if (prev != NULL) {
					prev->next = p->right;
				} else {
					next_level_start = p->right;
				}
				prev = p->right;
			}
			p = p->next;
			if (p == NULL) {
				p = next_level_start;
				next_level_start = NULL;
				prev = NULL;
			}
		}
	}
#endif
};
