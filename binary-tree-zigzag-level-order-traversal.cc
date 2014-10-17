// https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// http://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/
// http://leetcode.com/2010/09/printing-binary-tree-in-zig-zag-level_18.html

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > res;
		vector<int> values;
		stack<TreeNode*> currentLevel, nextLevel;
		bool leftToRight = true;

		currentLevel.push(root);
		while (!currentLevel.empty()) {
			TreeNode *node = currentLevel.top();
			currentLevel.pop();

			if (node != NULL) {
				values.push_back(node->val);
				if (leftToRight) {
					nextLevel.push(node->left);
					nextLevel.push(node->right);
				} else {
					nextLevel.push(node->right);
					nextLevel.push(node->left);
				}
			}

			if (currentLevel.empty()) {
				if (!values.empty()) {
					res.push_back(values);
					values.clear();
				}

				leftToRight = !leftToRight;
				swap(currentLevel, nextLevel);
			}
		}

		return res;
	}
};

int main(int argc, char const* argv[]) {
	TreeNode *a1 = new TreeNode(1);
	TreeNode *a2 = new TreeNode(2);
	TreeNode *a3 = new TreeNode(3);
	TreeNode *a4 = new TreeNode(4);
	TreeNode *a5 = new TreeNode(5);

	a1->left = a2;
	a2->left = a4;
	a1->right = a3;
	a3->right = a5;

	Solution s;
	vector<vector<int> > v = s.zigzagLevelOrder(a1);

	for (auto &vv : v) {
		for (auto n : vv) {
			cout << n << " ";
		}
		cout << endl;
	}
	return 0;
}
