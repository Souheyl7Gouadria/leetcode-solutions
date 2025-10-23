class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        int last = findBound(nums, target, false);
        return {first,last};
    }

    int findBound(vector<int> & nums, int target, bool isFirst){
        int l = 0, r = nums.size()-1, ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                ans = mid;
                if(isFirst) r = mid-1;
                else l = mid+1;
            }else if(nums[mid] > target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};