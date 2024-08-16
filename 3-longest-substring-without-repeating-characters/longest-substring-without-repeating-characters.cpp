class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int l = 0, r = 0, res = 0;
        while (r < s.size()) {
            if (st.count(s[r]) == 1) {
                st.erase(s[l]);
                l++;
            } else {
                st.insert(s[r]);
                res = max(res, r - l + 1);
                r++;
            }
        }
        return res;
    }
};