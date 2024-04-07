class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n,-1);
        // base case 
        dp[n-1] = 1;
        // tabulation (bottom up approach)
        for(int i=n-2;i>=0;i--){
            // 0 is a blocking value, impossible to reach the end
            if(nums[i] == 0){
                dp[i] = 0;
                continue;
            }
            // max index to jump to from current position
            int reach = nums[i]+i;
            for(int j=i+1;j<=reach;j++){
                if(j<n && dp[j]){
                    // can reach the last one from the (i)th index directly or by passing through previous one
                    dp[i] = 1;
                    break;
                }
            }
            // if the dp[i] is not set to 1 ,then we cant reach the last index
            if(dp[i] == -1){
                dp[i] = 0;
            }
        } 
        return dp[0];
    }
};