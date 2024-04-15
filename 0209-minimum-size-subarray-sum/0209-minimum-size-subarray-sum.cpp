class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int resp = 1e6;
        int sum = 0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                resp = min(resp,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if(resp == 1e6) return 0;
        return resp;
       
    }
};