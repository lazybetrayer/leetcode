// https://oj.leetcode.com/problems/unique-binary-search-trees-ii/

#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode *> generateTrees(int start, int end) {
		vector<TreeNode *> res;

		if (start > end) {
			res.push_back(NULL);
			return res;
		}

		for (int i = start; i <= end; i++) {
			vector<TreeNode *> leftTrees = generateTrees(start, i-1);
			vector<TreeNode *> rightTrees = generateTrees(i+1, end);

			for (vector<TreeNode *>::iterator it1 = leftTrees.begin(); it1 != leftTrees.end(); ++it1) {
				for (vector<TreeNode *>::iterator it2 = rightTrees.begin(); it2 != rightTrees.end(); ++it2) {
					TreeNode *root = new TreeNode(i);

					root->left = *it1;
					root->right = *it2;
					res.push_back(root);
				}
			}
		}

		return res;
	}
	vector<TreeNode *> generateTrees(int n) {
		return generateTrees(1, n);
	}
};
