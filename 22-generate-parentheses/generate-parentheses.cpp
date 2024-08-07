class Solution {
public:
    
void generate(int n, int openCount, int closeCount, string str, vector<string>& result) {
    if (closeCount == n) {
        result.push_back(str);
        return;
    }
    if (openCount < n) {
        generate(n, openCount + 1, closeCount, str + '(', result);
    }
    if (openCount > closeCount) {
        generate(n, openCount, closeCount + 1, str + ')', result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    generate(n, 0, 0, "", res);
    return res;
}
};