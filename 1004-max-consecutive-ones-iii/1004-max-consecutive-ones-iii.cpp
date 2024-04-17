class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int resp = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                k--;
            }
            if(k<0){
                if(nums[l] == 0){
                    // window shrink
                    k++;
                }
                // keep moving from left to right until the first 0
                l++;
            }else{
                resp = max(resp,i-l+1);
            }
        }
        return resp;
        
    }
};