// https://leetcode.com/problems/binary-tree-right-side-view/

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
	vector<int> rightSideView(TreeNode *root) {
		vector<int> v;
		queue<TreeNode *> q;

		if (root) q.push(root);

		while (!q.empty()) {
			int n = q.size();
			while (n--) {
				TreeNode *p = q.front();
				q.pop();
				if (p->left) q.push(p->left);
				if (p->right) q.push(p->right);
				if (n == 0) {
					v.push_back(p->val);
				}
			}
		}

		return v;
	}
};
