class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = l + k - 1;

        vector<int> res;
        deque<int> dq;

        int m = INT_MIN;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        l++;
        r++;
        m = dq[0];
        // dq.pop_front();
        res.push_back(m);

        while (r < nums.size()) {
            if (dq[0] == nums[l - 1]) {
                dq.pop_front();
            }
            while (!dq.empty() && dq.back() < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(nums[r]);
            l++;
            r = l + k - 1;
            m = dq[0];
            res.push_back(m);
        }
        return res;
    }
};