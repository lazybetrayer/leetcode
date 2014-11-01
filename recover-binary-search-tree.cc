// https://oj.leetcode.com/problems/recover-binary-search-tree/

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// 中序遍历记录前驱，比较前驱的值和当前节点的值
	// 可能会有1个(交换的是中序遍历相邻的两个节点)或2个逆序
	// 第一个节点为第一个逆序的第一个节点
	// 第二个节点为最后一个逆序的第二个节点
	// O(n) time, O(logn) space
	void recoverTree(TreeNode *r, TreeNode *&prev, TreeNode *&a, TreeNode *&b) {
		if (r == NULL) {
			return;
		}

		recoverTree(r->left, prev, a, b);

		if (prev != NULL && prev->val > r->val) {
			// 找到一个逆序
			if (a == NULL) {
				a = prev;
			}
			b = r;
		}

		prev = r;
		recoverTree(r->right, prev, a, b);
	}

	void recoverTree(TreeNode *root) {
		TreeNode *prev, *a, *b;
		prev = a = b = NULL;
		recoverTree(root, prev, a, b);
		swap(a->val, b->val);
	}
};

int main(int argc, char *argv[])
{
	return 0;
}

