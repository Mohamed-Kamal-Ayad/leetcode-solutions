class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        for (int i = nums.size() - 3; i >= 0; i--) {
            if (!((i + 3) <= (nums.size() - 1)))
                nums[i] += nums[i + 2];
            else
                nums[i] += max(nums[i + 2], nums[i + 3]);
        }
        return max(nums[0], nums[1]);
    }
};