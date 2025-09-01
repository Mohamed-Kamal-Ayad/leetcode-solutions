class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> maxHeap;
        for (auto point : points) {
            int distance = point[0] * point[0] + point[1] * point[1];
            maxHeap.push({distance, point[0], point[1]});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back({maxHeap.top()[1], maxHeap.top()[2]});
            maxHeap.pop();
        }
        return res;
    }
};