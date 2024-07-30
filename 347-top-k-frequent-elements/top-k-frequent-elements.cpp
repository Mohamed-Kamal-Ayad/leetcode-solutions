class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer;
        unordered_map<int, int> freqs;
        for (int num : nums) {
            freqs[num]++;
        }
        while (k > 0)
        {
           auto max = freqs.begin();
            for (auto it = freqs.begin(); it != freqs.end(); it++) {
               if (it->second > max->second) max = it;
            }
            answer.push_back(max->first);
            freqs.erase(max->first);
            k--;
        }

        return answer;
    }
};