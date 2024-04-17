class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            right+=nums[i];
        }
        int left = 0;
        for(int i=0;i<n;i++){
            right-=nums[i];
            if(right == left) return i;
            left+=nums[i];
        }
        return -1;
    }
};