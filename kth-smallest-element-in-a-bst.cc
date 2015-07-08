//https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 中序遍历第k个节点
    TreeNode *kthSmallestHelper(TreeNode* root, int &k) {
        if (root && k > 0) {
            TreeNode *p = kthSmallestHelper(root->left, k);
            if (p) return p;

            if (--k == 0) {
                return root;
            }

            p = kthSmallestHelper(root->right, k);
            if (p) return p;
        }
        return nullptr;
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *p = kthSmallestHelper(root, k);
        return p->val;
    }
};
