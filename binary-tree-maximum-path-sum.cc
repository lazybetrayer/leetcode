// https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/

// http://fisherlei.blogspot.com/2013/01/leetcode-binary-tree-maximum-path-sum.html
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//max_path(r): 从节点r到子树中节点路径和的最大值
//max_path(r) = max {
//	max_path(r.left)+r.val,
//	max_path(r.right)+r.val,
//	r.val,
//}
//
//max_path_sum(r): 经过节点r的最大路径和
//max_path_sum(r) = max {
//	r.val
//	max_path(r.left)+r.val,
//	max_path(r.right)+r.val,
//	max_path(r.left)+max_path(r.right)+r.val
//}
int maxPathSum(TreeNode *r, int &max_path_sum) {
	if (r == NULL) {
		return 0;
	}

	int curr_path_sum = r->val;
	int lmax_path = maxPathSum(r->left, max_path_sum);
	int rmax_path = maxPathSum(r->right, max_path_sum);

	if (lmax_path > 0) {
		curr_path_sum += lmax_path;
	}

	if (rmax_path > 0) {
		curr_path_sum += rmax_path;
	}

	if (curr_path_sum > max_path_sum) {
		max_path_sum = curr_path_sum;
	}

	return max(max(lmax_path, rmax_path) + r->val, r->val);
}

int maxPathSum(TreeNode *r) {
	if (r == NULL) {
		return 0;
	}

	int max_path_sum = r->val;
	maxPathSum(r, max_path_sum);
	return max_path_sum;
}

int main(int argc, char const* argv[])
{
	TreeNode *root = new TreeNode(1);
	TreeNode *l = new TreeNode(-2);
	TreeNode *r = new TreeNode(3);

	root->left = l;
	root->right = r;
	cout << maxPathSum(root) << endl;
	return 0;
}
