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
    void binaryTreePaths(TreeNode *root, vector<string> &v, string path) {
        if (!root) return;

        if (!root->left && !root->right) {
            path += to_string(root->val);
            v.push_back(path);
            return;
        }

        path += to_string(root->val) + "->";
        binaryTreePaths(root->left, v, path);
        binaryTreePaths(root->right, v, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        binaryTreePaths(root, v, "");
        return v;
    }
};
