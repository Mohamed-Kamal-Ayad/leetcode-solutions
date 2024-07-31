class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer;
    unordered_map<int, int> freqs;
    map<int, vector<int>> buckets;
    for (int num : nums) {
        freqs[num]++;
    }

    for (auto it = freqs.begin(); it != freqs.end(); it++) {
        buckets[it->second].push_back(it->first);
    }

    for (auto it = buckets.rbegin(); it != buckets.rend(); it++)
    {
        if (answer.size() == k) break;
        answer.insert(answer.end(), it->second.begin(), it->second.end());

    }
    return answer;
    }
};