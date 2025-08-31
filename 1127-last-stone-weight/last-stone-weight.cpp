class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int> s = stones;
        priority_queue<int> maxHeap(s.begin(), s.end());
        while (maxHeap.size() > 1) {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            int z = abs(x - y);
            if (z > 0)
                maxHeap.push(z);
        }
        return maxHeap.size() == 1 ? maxHeap.top() : 0;
    }
};