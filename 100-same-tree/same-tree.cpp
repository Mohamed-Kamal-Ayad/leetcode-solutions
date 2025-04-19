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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool b = true;
        return dfs(p, q, b);
    }

    bool dfs(TreeNode* rootp, TreeNode* rootq, bool& b) {
        if (!rootp && !rootq) {
            return b;
        }
        if (!rootp || !rootq) {
            b = false;
            return b;
        }
        if (rootp->val != rootq->val)
            b = false;
        dfs(rootp->left, rootq->left, b);
        dfs(rootp->right, rootq->right, b);
        return b;
    }
};