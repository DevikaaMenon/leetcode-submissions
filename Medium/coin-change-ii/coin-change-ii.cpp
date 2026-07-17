class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int& c : coins)
            for (int i = c; i <= amount; i++) {
                dp[i] += dp[i - c];
                dp[i] = min(dp[i], (long long)INT_MAX); // clamp
            }

        return (int)dp[amount];
    }
};