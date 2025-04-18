/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool b = true;
        if (!root) {
            return true;
        }
        dfs(root, b);
        return b;
    }

    int dfs(TreeNode* root, bool& b) {
        if (!root) {
            return 0;
        }
        int left = dfs(root->left, b);
        int right = dfs(root->right, b);
        if (abs(left - right) > 1)
            b = false;
        return 1 + max(left, right);
    }
};