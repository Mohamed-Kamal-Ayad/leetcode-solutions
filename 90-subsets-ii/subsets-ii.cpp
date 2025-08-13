class Solution {
public:
    void backtrack(vector<int>& nums, int i, vector<int> subset,
                   vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        backtrack(nums, i + 1, subset, res);
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
        subset.pop_back();
        backtrack(nums, i + 1, subset, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums, 0, subset, res);
        return res;
    }
};