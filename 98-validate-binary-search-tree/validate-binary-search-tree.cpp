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
    bool dfs(TreeNode* root, long long minInterval, long long maxInterval) {
        if (!root) {
            return true;
        }
        if (!(root->val > minInterval && root->val < maxInterval))
            return false;
        bool left = dfs(root->left, minInterval, root->val);
        bool right = dfs(root->right, root->val, maxInterval);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        long long minInterval = LONG_LONG_MIN;
        long long maxInterval = LONG_LONG_MAX;
        return dfs(root, minInterval, maxInterval);
    }
};