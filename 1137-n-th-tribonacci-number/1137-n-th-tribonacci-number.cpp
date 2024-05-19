class Solution {
public:

    int helper(int idx , vector <int> &dp) {
        // base case
        if(idx == 0) return 0;
        if(idx == 1) return 1;
        if(idx == 2) return 1;
        // pre-calculated values
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = helper(idx-3,dp)+helper(idx-2,dp)+helper(idx-1,dp);
    }

    int tribonacci(int n) {  
        vector <int> dp(n+1,-1);  
        return helper(n,dp);
    }
};