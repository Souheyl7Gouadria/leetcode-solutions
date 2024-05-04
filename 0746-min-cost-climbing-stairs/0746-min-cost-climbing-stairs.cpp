class Solution {
public:

    int mincost(int pos,vector<int>& cost,vector<int>& dp){
        int n = cost.size();
        // base case 
        if(dp[pos] != -1) return dp[pos];
        return dp[pos] = cost[pos] + min(mincost(pos+1,cost,dp),mincost(pos+2,cost,dp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector <int> dp(n+1,0);
        dp[n] = 0;
        for(int i=n-1;i>=0;i--){
            int oneStep=dp[i+1];
            int twoSteps=1000;
            if(i<=n-2){
                twoSteps=dp[i+2];
            }
            dp[i] = cost[i] + min(oneStep,twoSteps);
        }
        return min(dp[0],dp[1]);
    }
};