class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int, int>> st;
    vector<int> res(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!st.empty() && temperatures[i] > st.top().first)
        {
            auto t = st.top();
            st.pop();
            res[t.second] = i - t.second;
        }
        st.push({ temperatures[i], i });
    }
    return res;
}
};