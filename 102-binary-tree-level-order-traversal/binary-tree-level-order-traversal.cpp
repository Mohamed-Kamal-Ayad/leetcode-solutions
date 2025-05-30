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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if (!root) return levels;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> l;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node) {
                    l.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (!l.empty()) {
                levels.push_back(l);
            }
        }
        return levels;
    }
};