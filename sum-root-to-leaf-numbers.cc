// https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void sumNumbers(TreeNode *root, int n, int &sum) {
	if (root == NULL) {
		return;
	}

	if (root->left == NULL && root->right == NULL) {
		sum += 10 * n + root->val;
		return;
	}

	if (root->left) {
		sumNumbers(root->left, 10 * n + root->val, sum);
	}

	if (root->right) {
		sumNumbers(root->right, 10 * n + root->val, sum);
	}
}

int sumNumbers(TreeNode *root) {
	int n = 0;
	int sum = 0;

	sumNumbers(root, n, sum);
	return sum;
}
