class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2)
            return min(cost[0], cost[1]);
        vector<int> dp(cost.size() + 1);
        dp[1] = cost[0];
        dp[2] = cost[1];
        for (int i = 3; i <= cost.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i - 1];
        }
        return min(dp[cost.size()], dp[cost.size() - 1]);
    }
};