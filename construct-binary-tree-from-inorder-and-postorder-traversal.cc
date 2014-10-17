// https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <vector>
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
	TreeNode *buildTree(const vector<int> &inorder, int b1, int e1, const vector<int> &postorder, int b2 ,int e2) {
		if (b1 > e1 || b2 > e2) {
			return NULL;
		}

		int root_val = postorder[e2];
		int i = b1;

		while (i < e1 && inorder[i] != root_val) {
			i++;
		}

		if (i > e1) {
			return NULL;
		}

		TreeNode *root = new TreeNode(root_val);

		root->left = buildTree(inorder, b1, i - 1, postorder, b2, b2 + i - b1 - 1);
		root->right = buildTree(inorder, i + 1, e1, postorder, b2 + i - b1, e2 - 1);
		return root;
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
};

void inorder_traverse(TreeNode *r) {
	if (r) {
		inorder_traverse(r->left);
		cout << r->val << " ";
		inorder_traverse(r->right);
	}
}

void postorder_traverse(TreeNode *r) {
	if (r) {
		inorder_traverse(r->left);
		inorder_traverse(r->right);
		cout << r->val << " ";
	}
}

int main(int argc, char const* argv[])
{
	vector<int> inorder{-1};
	vector<int> postorder{-1};

	Solution s;
	TreeNode *root = s.buildTree(inorder, postorder);
	inorder_traverse(root);
	cout << endl;
	postorder_traverse(root);
	cout << endl;
	return 0;
}
