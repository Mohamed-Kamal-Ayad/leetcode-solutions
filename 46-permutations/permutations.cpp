class Solution {
public:
    void backtrack(vector<int>& nums, int cur, vector<int>& perm,
                   vector<vector<int>>& res) {

        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(perm.begin(), perm.end(), nums[i]) == perm.end()) {
                perm.push_back(nums[i]);
                backtrack(nums, i, perm, res);
                perm.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        backtrack(nums, 0, perm, res);
        return res;
    }
};