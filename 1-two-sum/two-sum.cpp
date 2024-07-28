class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
                vector<int> indexes;
    unordered_map<int, int> sums;
    for (int i = 0; i < nums.size(); i++)
    {
        if (sums.find(target - nums[i]) != sums.end()) {
            indexes.push_back(sums[target - nums[i]]);
            indexes.push_back(i);
            break;
        }
        sums[nums[i]] = i;
    }
    return indexes;
    }
};