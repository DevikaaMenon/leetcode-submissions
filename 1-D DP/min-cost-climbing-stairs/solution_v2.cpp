class Solution {
public:
    int n;
    int solve(int i,vector<int>& cost,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=cost[i]+min(solve(i+1,cost,dp),solve(i+2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //naive solution is to calculate dfs(i): how to reach the top from the ith stair
        n=cost.size();
        vector<int>dp(n+1,-1);
        return min(solve(0,cost,dp),solve(1,cost,dp));
        //might run into a tle idk
    }
};