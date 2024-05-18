class Solution {
public:
    
    int steal(vector <int> & nums,vector <int> & dp, int index){
        int n = nums.size();
        // base case
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        return dp[index] = nums[index] + max(steal(nums,dp,index+2),steal(nums,dp,index+3));
        
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n+1,-1);
        return max(steal(nums,dp,0),steal(nums,dp,1));
    }
};