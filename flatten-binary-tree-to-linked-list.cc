// https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
	void flatten(TreeNode *root, TreeNode *&prev) {
		if (root == NULL) {
			return;
		}

		if (prev != NULL) {
			prev->right = root;
		}

		prev = root;

		// 保存right孩子，防止递归左子树时修改了此节点的right指针
		TreeNode *right = root->right;

		flatten(root->left, prev);
		root->left = NULL;
		flatten(right, prev);
	}

	void flatten(TreeNode *root) {
		// prev保存线序遍历的前驱
		TreeNode *prev = NULL;
		flatten(root, prev);
	}
};

int main(int argc, char const* argv[])
{
	TreeNode *a1 = new TreeNode(1);
	TreeNode *a2 = new TreeNode(2);
	TreeNode *a3 = new TreeNode(3);
	TreeNode *a4 = new TreeNode(4);
	TreeNode *a5 = new TreeNode(5);
	TreeNode *a6 = new TreeNode(6);

	a1->left = a2;
	a1->right = a5;
	a2->left = a3;
	a2->right = a4;
	a5->right = a6;

	Solution s;
	s.flatten(a1);

	while (a1) {
		cout << a1->val << " ";
		a1 = a1->right;
	}
	return 0;
}
