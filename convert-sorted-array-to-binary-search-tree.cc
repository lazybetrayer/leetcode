// https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
	TreeNode *sortedArrayToBST(vector<int> &num, int start, int end) {
		if (start > end) {
			return NULL;
		}

		vector<int>::size_type mid = start + (end - start) / 2;
		TreeNode *root = new TreeNode(num[mid]);
		root->left = sortedArrayToBST(num, start, mid - 1);
		root->right = sortedArrayToBST(num, mid + 1, end);

		return root;
	}

	TreeNode *sortedArrayToBST(vector<int> &num) {
		return sortedArrayToBST(num, 0, num.size() - 1);
	}
};
