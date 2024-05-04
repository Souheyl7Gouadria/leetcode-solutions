class Solution {
public:
    
    int robHouse(int pos,vector<int>& nums,vector<int>& dp){
        
        int n = nums.size();
        // base case
        if(pos>=n) return 0;
        if(dp[pos] != -1) return dp[pos];
        return dp[pos] = nums[pos]+max(robHouse(pos+2,nums,dp),robHouse(pos+3,nums,dp));
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n,-1);
        int resp = INT_MIN;
        for(int i=0;i<n;i++){
            resp=max(resp,robHouse(i,nums,dp));
        }
        return resp;
    }
};