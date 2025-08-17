class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string s;
        if (!digits.empty())
            backtrack(digits, 0, res, s);
        return res;
    }

private:
    unordered_map<char, string> phone{{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                      {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                      {'8', "tuv"}, {'9', "wxyz"}};

    void backtrack(string digits, int i, vector<string>& res, string s) {
        if (s.size() == digits.length()) {
            res.push_back(s);
            return;
        }

        for (char c : phone[digits[i]]) {
            backtrack(digits, i + 1, res, s + c);
        }
    }
};