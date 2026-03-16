class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(),copy.end());
        for(int i = 0; i<nums.size(); i++){
            nums[i] = lower_bound(copy.begin(),copy.end(),nums[i])- copy.begin();
        }
        return nums;
    }
};