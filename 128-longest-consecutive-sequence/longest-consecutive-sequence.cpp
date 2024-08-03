class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    set<int> seq(nums.begin(), nums.end());
    int counter = 1;
    int temp = 1;
    if(nums.size() == 0) return 0;
    for (auto itr = seq.begin(); itr != seq.end(); itr++) {
        auto next_itr = next(itr);
        int diff = abs(*itr - *next_itr);
        if (diff == 1 && next_itr != seq.end()) {
            temp++;
            if (temp > counter) {
                counter = temp;
            }
        }
        else {
            temp = 1;
        }
    }
    return counter;
    }
};