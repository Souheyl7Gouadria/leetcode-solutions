class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int m;
        while(l<=r){
            m = l +(r-l)/2;

            if(nums[m] == target) return true;

            if(nums[l] < nums[m]){ // means left half is sorted
                if(nums[l] <= target && target < nums[m]){ // search left
                    r = m-1;
                }else{
                    l = m+1;
                }
            }else if(nums[l] > nums[m]){ // means right half is sorted
                if(nums[m] < target && target <= nums[r]){ // cant have nums[m] <= target, we checked that, searching right
                    l = m + 1;
                }else{
                    r = m-1;
                }
            }else{
                l++;
            }
        }
        return false;
    }
};