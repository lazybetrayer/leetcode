// https://oj.leetcode.com/problems/path-sum-ii/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void pathSum(TreeNode *root, vector<int> &path, int sum, vector<vector<int> > &res) {
		if (root == NULL) return;

		if (!root->left && !root->right) {
			if (sum == root->val) {
				path.push_back(root->val);
				res.push_back(path);
				path.pop_back();
			}
			return;
		}

		path.push_back(root->val);
		pathSum(root->left, path, sum - root->val, res);
		pathSum(root->right, path, sum - root->val, res);
		path.pop_back();
	}
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > res;
		vector<int> path;
		pathSum(root, path, sum, res);
		return res;
	}
};
