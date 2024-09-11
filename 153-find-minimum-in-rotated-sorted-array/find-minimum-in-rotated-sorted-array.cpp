class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int low = 0;
        int high = nums.size() - 1;
        int mini;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if ((mid == 0 && nums[mid] < nums[mid + 1]) ||
                mid == (nums.size() - 1)) {
                mini = nums[0];
                break;
            }
            if (nums[mid] < nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                if (nums[mid] > nums[0]) {
                    low = mid + 1;
                    continue;
                } else {
                    high = mid - 1;
                    continue;
                }
            } else if (nums[mid] > nums[mid + 1]) {
                mini = nums[mid + 1];
                break;
            } else {
                mini = nums[mid];
                break;
            }
        }
        return mini;
    }
};