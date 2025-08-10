class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, int sum,
              vector<int>& subset, vector<vector<int>>& res) {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            res.push_back(subset);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            subset.push_back(candidates[i]);
            backtrack(candidates, target, i + 1, sum + candidates[i], subset, res);
            while (i + 1 < candidates.size() &&
                   candidates[i] == candidates[i + 1]) {
                i++; 
            }
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        backtrack(candidates, target, 0, 0, subset, res);
        return res;
    }
};