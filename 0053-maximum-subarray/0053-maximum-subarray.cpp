class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int resp = nums[0];
        int currSum=0;
        for(int ele : nums){
            if(currSum<0){
                currSum=0;
            }
            currSum+=ele;
            resp = max(resp,currSum);
        }
        return resp;
    }
};