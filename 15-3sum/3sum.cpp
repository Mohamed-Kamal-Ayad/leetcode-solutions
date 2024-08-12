class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        int x, y, z;
        int l, r;
        for (int i = 0; i < nums.size(); i++) {
            x = -nums[i];
            l = i + 1;
            r = nums.size() - 1;
            vector<int> v;
            while (l < r) {
                y = nums[l];
                z = nums[r];
                int sum = y + z;
                if (sum > x) {
                    r--;
                } else if (sum < x) {
                    l++;
                } else {
                    v.push_back(-x);
                    v.push_back(y);
                    v.push_back(z);
                    s.insert(v);
                    v.clear();
                    l++;
                    r--;
                }
            }
        }
        vector<vector<int>> v(s.begin(), s.end());
        return v;
    }
};