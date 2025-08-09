class Solution {
public:
    void dfs(vector<int>& candidates, int target, int start, int& sum,
             vector<int>& subset, vector<vector<int>>& res) {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            res.push_back(subset);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            sum += candidates[i];
            subset.push_back(candidates[i]);
            dfs(candidates, target, i, sum, subset, res);
            sum -= candidates[i];
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        vector<int> subset;
        vector<vector<int>> res;
        dfs(candidates, target, 0, sum, subset, res);
        return res;
    }
};