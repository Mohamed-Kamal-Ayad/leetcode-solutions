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
    int dfs(TreeNode* root, int& k, int& res) {
        if (!root)
            return -1;
        dfs(root->left, k, res);
        if (--k == 0) {
            res = root->val;
        }
        dfs(root->right, k, res);
        return res;
    }

    int kthSmallest(TreeNode* root, int k) {
        int res;
        return dfs(root, k, res);
    }
};