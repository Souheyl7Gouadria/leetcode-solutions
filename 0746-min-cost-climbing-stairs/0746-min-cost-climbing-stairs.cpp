class Solution {
public:

    int helper(vector <int> &cost , vector <int> &dp, int idx){
        int n = cost.size();
        // base case 
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = cost[idx] + min(helper(cost ,dp, idx+1),helper(cost ,dp, idx+2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector <int> dp(n+1,-1);
        return min(helper(cost,dp,0),helper(cost,dp,1));
    }
};