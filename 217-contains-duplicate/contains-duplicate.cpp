class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto num : nums){
            if(freq.contains(num)) return true;
            else freq.insert({num,1});
        }  
        return false;
    }
};