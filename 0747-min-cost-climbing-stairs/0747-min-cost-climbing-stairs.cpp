class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector <int> dp(n+2,0);
        // base case already set to 0
        
        // recursion from 0 -> n , tab will be from n->0
        for(int i=n-1;i>=0;i--){
            int moveOne = dp[i+1];
            int moveTwo = dp[i+2];
            dp[i] = cost[i] + min(moveOne,moveTwo);
        }
        return min(dp[0],dp[1]);
        
    }
};