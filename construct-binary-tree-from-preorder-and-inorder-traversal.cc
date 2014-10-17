// https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
	TreeNode *buildTree(const vector<int> &preorder, int b1, int e1, const vector<int> &inorder, int b2, int e2) {
		if (b1 > e1 || b2 > e2) {
			return NULL;
		}

		int root_val = preorder[b1];
		int i = b2;

		while (i < e2 && inorder[i] != root_val) {
			i++;
		}

		if (i > e2) {
			return NULL;
		}

		TreeNode *root = new TreeNode(root_val);

		root->left = buildTree(preorder, b1 + 1, b1 + i - b2, inorder, b2, i - 1);
		root->right = buildTree(preorder, b1 + i - b2 + 1, e1, inorder, i + 1, e2);
		return root;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
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
