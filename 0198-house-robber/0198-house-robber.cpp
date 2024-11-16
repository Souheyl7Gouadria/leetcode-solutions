class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n+3,0); 
        // recursion if from 0 -> n
        // tabulation will be from n -> 0
        for(int i=n-1;i>=0;i--){
            int twoSteps = dp[i+2];
            int threeSteps = dp[i+3];
            dp[i] = nums[i] + max(twoSteps,threeSteps);
        }
        return max(dp[0],dp[1]);
        
    }
};