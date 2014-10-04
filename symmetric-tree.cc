// https://oj.leetcode.com/problems/symmetric-tree/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode *left, TreeNode *right)
{
	if (left == NULL && right == NULL) {
		return true;
	}

	if (left == NULL || right == NULL) {
		return false;
	}

	if (left->val != right->val) {
		return false;
	}

	return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode *r)
{
	if (r == NULL) {
		return true;
	}

	return isSymmetric(r->left, r->right);
}
