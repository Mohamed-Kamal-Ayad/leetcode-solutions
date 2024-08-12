class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        int x, y, z;
        int l, r;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            x = -nums[i];
            l = i + 1;
            r = nums.size() - 1;
            while (l < r) {
                y = nums[l];
                z = nums[r];
                int sum = y + z;
                if (sum > x) {
                    r--;
                } else if (sum < x) {
                    l++;
                } else {
                    v.push_back({-x, y, z});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }
        return v;
    }
};