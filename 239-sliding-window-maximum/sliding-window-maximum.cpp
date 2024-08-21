class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = 0;

        vector<int> res;
        deque<int> dq; // store indexes
        while (r < nums.size()) {
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);
            if (l > dq[0]) {
                dq.pop_front();
            }
            if ((r + 1) >= k) {
                res.push_back(nums[dq[0]]);
                l++;
            }
            r++;
        }
        return res;
    }
};