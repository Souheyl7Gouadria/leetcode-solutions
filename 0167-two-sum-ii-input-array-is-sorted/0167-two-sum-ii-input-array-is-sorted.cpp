class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int n = nums.size();
        int r = n-1;
        while(l<r){
            if(nums[r]+nums[l] == target){
                return{l+1,r+1};
            }else if(nums[r]+nums[l] < target){
                l++;
            }else{
                r--;
            }
        }
        return {};
    }
};