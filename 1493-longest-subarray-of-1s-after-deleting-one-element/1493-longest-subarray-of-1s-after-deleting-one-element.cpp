class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0; // points to the left edge of the window
        int zeros = 0;
        int resp = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                zeros++;
            }
            while(zeros>1){
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }
            resp = max(resp,i-l);
        }
        if(zeros == 0) return n-1;
        return resp;
    }
};