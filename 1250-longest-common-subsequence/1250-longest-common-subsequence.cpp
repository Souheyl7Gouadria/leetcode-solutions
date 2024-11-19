class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size()-1;
        int m = text2.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(text1,n,text2,m,dp);
    }
    int helper (string &text1,int n, string &text2,int m , vector<vector<int>> &dp){
        if(n<0 || m<0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(text1[n] == text2[m]){
            return dp[n][m] = 1 + helper(text1,n-1,text2,m-1,dp);
        }
        return dp[n][m] = max(helper(text1,n-1,text2,m,dp),helper(text1,n,text2,m-1,dp));
    }
};