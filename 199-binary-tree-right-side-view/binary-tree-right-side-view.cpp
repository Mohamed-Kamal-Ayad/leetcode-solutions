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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if (!root)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                TreeNode* valid;
                if (currNode) {
                    valid = currNode;
                    q.push(currNode->left);
                    q.push(currNode->right);
                }
                if (size - i == 1 && !q.empty()) {
                    v.push_back(valid->val);
                }
            }
        }
        return v;
    }
};