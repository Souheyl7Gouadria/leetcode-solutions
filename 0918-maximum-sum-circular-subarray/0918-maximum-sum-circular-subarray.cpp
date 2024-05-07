class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax=0;
        int globalMax=nums[0];
        int currMin=0;
        int globalMin=nums[0];
        int total = 0;
        for(int ele : nums){
            total+=ele;
            currMax=max(ele,ele+currMax);
            globalMax=max(currMax,globalMax);
            currMin=min(ele,ele+currMin);
            globalMin=min(globalMin,currMin);
        }
        if(globalMax<0) return globalMax;
        return max(globalMax,total-globalMin);
    }
};