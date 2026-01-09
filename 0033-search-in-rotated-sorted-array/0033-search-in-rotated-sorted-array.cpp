class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int m;
        // looking for the pivot(dividing nums into 2 sorted subsegments)
        while(l < r){
            m = l+(r-l)/2;
            if(nums[m] > nums[r]) l = m+1; // rotation happened in the right segment, index 'm' excluded
            else r = m; // rotation in the left segment, index 'm' included
        }
        int pivot = l;

        // look for target in the right side
        int resp = binarySearch(nums,target,pivot,n-1);
        if(resp != -1) return resp;
        // look for target in th left side
        return binarySearch(nums,target,0,pivot-1);
    }

    int binarySearch(vector<int>& nums, int target, int l, int r){
        int m;
        while(l <= r){
            m = l+(r-l)/2;
            if(nums[m] == target) return m;
            if(nums[m] > target) r = m-1;
            else l = m+1;
        }
        return -1;
    }
};