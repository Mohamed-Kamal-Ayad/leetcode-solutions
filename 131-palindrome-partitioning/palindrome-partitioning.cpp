class Solution {
public:
    void backtrack(int start, const string& s, vector<string>& part,
                   vector<vector<string>>& res) {
        if (start >= s.length()) {
            res.push_back(part);
            return;
        }

        for (int i = start; i <= s.length(); i++) {
            if (isPali(s, start, i)) {
                part.push_back(s.substr(start, i - start + 1));
                backtrack(i + 1, s, part, res);
                part.pop_back();
            }
        }
    }

    bool isPali(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        backtrack(0, s, part, res);
        return res;
    }
};