class Solution {
public:
    
    int minNumber(int idx, int amount, vector<int>& coins,vector <vector<int>> &dp){
        // base case
        if(idx == 0){
            if(amount%coins[0] == 0){
                return amount/coins[0];
            }else{
                return 1e9;
            }
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int notTake = minNumber(idx-1,amount,coins,dp);
        int take = 1e9;
        if(amount >= coins[idx]){
            take = 1 + minNumber(idx,amount-coins[idx],coins,dp);
        }
        return dp[idx][amount] = min(take,notTake);
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        vector <vector<int>> dp(n,vector <int> (amount+1,-1));
        int response =  minNumber(n-1,amount,coins,dp);
        if(response == 1e9){
            return -1;
        }
        return response;
    }
};