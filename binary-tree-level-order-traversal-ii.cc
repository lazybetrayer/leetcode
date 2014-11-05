// https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/

#include <algorithm>
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
#if 1
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
		if (root == NULL) return res;

		queue<TreeNode *> q;
		int curr_count = 1;

		q.push(root);

		while (!q.empty()) {
		    vector<int> v;
		    int next_count = 0;
			while (curr_count--) {
			    TreeNode *p = q.front();
			    q.pop();
			    v.push_back(p->val);

			    if (p->left) {
			        next_count++;
			        q.push(p->left);
			    }
			    if (p->right) {
			        next_count++;
			        q.push(p->right);
			    }
			}
			curr_count = next_count;
			res.push_back(v);
		}
		reverse(res.begin(), res.end());

		return res;
    }
#else
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
#endif
};
