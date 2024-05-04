class Solution {
public:

    int mincost(int pos,vector<int>& cost,vector<int>& dp){
        int n = cost.size();
        // base case 
        if(pos >= n) return 0;
        if(dp[pos] != -1) return dp[pos];
        return dp[pos] = cost[pos] + min(mincost(pos+1,cost,dp),mincost(pos+2,cost,dp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector <int> dp(n,-1);
        return min(mincost(0,cost,dp),mincost(1,cost,dp));
    }
};