class Solution {
public:
    void backtrack(vector<int>& nums, int cur, vector<vector<int>>& res) {

        if (cur == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = cur; i < nums.size(); i++) {
            swap(nums[cur], nums[i]);
            backtrack(nums, cur + 1, res);
            swap(nums[cur], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
};