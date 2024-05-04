class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        vector<int> dp(n + 2, 0);
        
        // Base case
        dp[n] = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            int movetwo = dp[i + 2];
            int movethree = INT_MIN;
            if (i < n - 2) {
                movethree = dp[i + 3];
            }
            dp[i] = nums[i] + max(movetwo, movethree);
        }
        
        return max(dp[0],dp[1]);
    }
};
