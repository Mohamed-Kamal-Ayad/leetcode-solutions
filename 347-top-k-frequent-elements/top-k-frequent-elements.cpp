class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> answer;
    unordered_map<int, int> freqs;
    for (int num : nums) {
        freqs[num]++;
    }

    vector<vector<int>> buckets(nums.size() + 1);
    for (auto it = freqs.begin(); it != freqs.end(); it++) {
        buckets[it->second].push_back(it->first);
    }

    for (int i = nums.size(); i >= 0; i--) {
        if (answer.size() == k) break;
        answer.insert(answer.end(), buckets[i].begin(), buckets[i].end());
    }
    return answer;
    }
};
