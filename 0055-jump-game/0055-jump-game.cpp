class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, 0);
        // base case 
        dp[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<=i+nums[i];j++){
               if(j<n && dp[j]==1) {
                    dp[i] = 1;
                    break; //we can reach the last index in nums from that index
               }
            }
        }
        return dp[0];
    }
};