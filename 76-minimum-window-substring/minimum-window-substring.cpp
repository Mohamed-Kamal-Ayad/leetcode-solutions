class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length() || t == "")
            return "";

        unordered_map<char, int> countT;
        unordered_map<char, int> window;

        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        int start = -1, end = -1;
        int res = INT_MAX;
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;
            if (countT.count(c) == 1 && window[c] == countT[c])
                have++;

            while (have == need) {
                if ((r - l + 1) < res) {
                    start = l;
                    end = r;
                    res = r - l + 1;
                }
                window[s[l]]--;
                if (countT.count(s[l]) == 1 && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return res != INT_MAX ? s.substr(start, res) : "";
    }
};