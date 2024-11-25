class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(amount,coins,n-1,dp);
    }

    int helper(int amount , vector<int>& coins , int index,vector<vector<int>>& dp){
        if(index < 0) return 0;
        if(amount == 0) return 1;
        if(dp[index][amount] != -1) return dp[index][amount];
        int notTake = helper(amount,coins,index-1,dp);
        int take = 0;
        if(amount >= coins[index]) take = helper(amount-coins[index],coins,index,dp);
        return dp[index][amount] = take+notTake;
    }
};