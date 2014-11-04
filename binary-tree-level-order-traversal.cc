// https://oj.leetcode.com/problems/binary-tree-level-order-traversal/

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > res;
		if (root == NULL) return res;

		queue<TreeNode *> q;
		vector<int> v;
		int curr_count = 1;
		int next_count = 0;

		q.push(root);

		while (!q.empty()) {
			TreeNode *p = q.front();
			q.pop();
			v.push_back(p->val);

			if (p->left) {
				q.push(p->left);
				next_count++;
			}

			if (p->right) {
				q.push(p->right);
				next_count++;
			}

			if (v.size() == curr_count) {
				res.push_back(v);
				v.clear();
				curr_count = next_count;
				next_count = 0;
			}
		}

		return res;
	}
};
