class Solution {
private:
    vector<int> dpVec = vector<int>(46, -1);

public:
    int climbStairs(int n) {
        if (n <= 1)
            return 1;
        if (dpVec[n] != -1)
            return dpVec[n];
        dpVec[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return dpVec[n];
    }
};