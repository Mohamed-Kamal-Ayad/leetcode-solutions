class Solution {

public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string s;
        backtrack(digits, 0, res, s);
        return res;
    }

private:
    unordered_map<char, string> phone{{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                      {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                      {'8', "tuv"}, {'9', "wxyz"}};

    void backtrack(string digits, int start, vector<string>& res, string& s) {
        if (start == digits.length()) {
            if (s.length() == digits.length() && !s.empty()) {
                res.push_back(s);
            }
            return;
        }

        for (int i = start; i < digits.size(); i++) {
            string ds = phone[digits[i]];
            for (char c : ds) {
                s.push_back(c);
                backtrack(digits, i + 1, res, s);
                s.pop_back();
            }
        }
    }
};