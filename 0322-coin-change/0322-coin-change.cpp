class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        vector <vector<int>> dp(n+1,vector <int> (amount+1,0));
        // base case
        for(int t = 0;t<=amount;t++){
            if(t%coins[0] == 0){
                dp[0][t] = t/coins[0];
            }else{
                dp[0][t] = 1e9;
            }
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                int notTake = dp[i-1][t];
                int take = 1e9;
                if(coins[i]<=t){
                    take = 1+dp[i][t-coins[i]];
                }
                dp[i][t] = min(take,notTake);
            }
        }
        
        int response = dp[n - 1][amount];
        if(response == 1e9){
            return -1;
        }
        return response;
    }
};