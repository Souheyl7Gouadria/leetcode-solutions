class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,0);

        //vector<int> dp(n,-1);
        //helper(0,nums,dp)

        // top down tabulation approach -> O(n²)
        for(int i=n-2;i>=0;i--){
            int maxJump = nums[i];
            int minNumberOfJumps = 1e5;
            for(int jump=i+1;jump<=i+maxJump;jump++){
                if(jump<=n-1) minNumberOfJumps = min(dp[jump]+1,minNumberOfJumps);
            }
            dp[i] = minNumberOfJumps;
        }
        return dp[0];
    }
    
// memoization approach

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