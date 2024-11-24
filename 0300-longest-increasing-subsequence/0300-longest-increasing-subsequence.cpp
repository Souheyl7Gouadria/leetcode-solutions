class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1)); // n choices for index and (n+1) for prev index including -1;
        return helper(nums,0,-1,dp);
    }

    int helper(vector<int>& nums , int index, int prevIndex,vector<vector<int>>& dp){
        int n = nums.size();
        //base case
        if(index == n) return 0;
        if(dp[index][prevIndex+1] != -1) return dp[index][prevIndex+1];

        int notTake = helper(nums,index+1,prevIndex,dp);
        int take = 0;
        if(prevIndex == -1 || nums[index] > nums[prevIndex]){
            take = 1 + helper(nums,index+1,index,dp);
        }
        return dp[index][prevIndex+1] = max(take,notTake);
    }
};