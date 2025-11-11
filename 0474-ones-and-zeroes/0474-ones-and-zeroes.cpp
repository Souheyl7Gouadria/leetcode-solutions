class Solution {
public:

    pair<int,int> countZeroOne(string str){
        int zeroCnt = 0, oneCnt = 0;
        for (char c : str){
            if (c == '0') zeroCnt++;
            else oneCnt++;
        }
        return {zeroCnt,oneCnt};
    }

    int helper(vector<string>& strs, int zerosLeft, int onesLeft, int index,vector<vector<vector<int>>>& dp){
        if (index >= strs.size()) return 0;

        // memoization check
        if (dp[index][zerosLeft][onesLeft] != -1) return dp[index][zerosLeft][onesLeft];

        pair<int,int> wordCount = countZeroOne(strs[index]);
        // pick
        int pick = 0;
        if (wordCount.first <= zerosLeft && wordCount.second <= onesLeft) pick = 1 + helper(strs,zerosLeft-wordCount.first,onesLeft-wordCount.second,index+1,dp);

        // not pick
        int notPick = helper(strs,zerosLeft,onesLeft,index+1,dp);

        return dp[index][zerosLeft][onesLeft] = max(pick,notPick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return helper(strs,m,n,0,dp);
    }
};