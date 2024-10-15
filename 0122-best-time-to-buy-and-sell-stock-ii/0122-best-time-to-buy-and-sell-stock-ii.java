class Solution {

    public int solve(int[] prices, int index, boolean canBuy , int[][] dp){
        // base case
        if(index == prices.length) return 0;
        int can = canBuy ? 1:0;
        if(dp[index][can] != -1) return dp[index][can];
        int profit = 0;
        if(canBuy){
            int buy = -prices[index] + solve(prices,index+1,false,dp);
            int notBuy = solve(prices,index+1,true,dp);
            profit = Math.max(buy,notBuy);
            dp[index][can] = profit;
        }else{
            int sell = prices[index] + solve(prices,index+1,true,dp);
            int notSell = solve(prices,index+1,false,dp);
            profit = Math.max(sell,notSell);
            dp[index][can] = profit;
        }

        return profit;


    }

    public int maxProfit(int[] prices) {
        int n = prices.length;
        int dp[][] = new int[n][2];
        for(int i = 0; i<n ;i++){
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        return solve(prices,0,true,dp);
    }
}