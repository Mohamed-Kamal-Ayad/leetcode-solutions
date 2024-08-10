class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    stack<pair<int, int>> s;
    int maxArea = 0;
    
    for (int i = 0; i < heights.size(); i++)
    {
        int start = i;
        while (!s.empty() && heights[i] < s.top().second)
        {
            auto temp = s.top();
            maxArea = max(maxArea, temp.second * (i - temp.first));
            start = temp.first;
            s.pop();
        }
        s.push({ start ,heights[i] });
    }

    while (!s.empty())
    {
        auto temp = s.top();
        int len = temp.second * (heights.size() - temp.first);
        maxArea = max(maxArea, len);
        s.pop();
    }

    return maxArea;
}
};