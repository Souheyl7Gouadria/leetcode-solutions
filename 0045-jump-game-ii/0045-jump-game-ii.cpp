class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(0,nums,dp);
    }
    int helper(int index , vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if(dp[index] != -1) return dp[index];
        if(index == n-1) return 0;
        int cnt=1e4;
        if(nums[index] == 0 || index > n-1) return 1e4;
        for(int i=1;i<=nums[index];i++){
            if(i+index < n) cnt = min(cnt,1+helper(i+index,nums,dp));
            else break;
        }
        return dp[index] = cnt; 
    }
};