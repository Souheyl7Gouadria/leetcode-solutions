class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int mid;
        while(l <= r){
            mid = l+(r-l)/2;
            if(sumOfDiv(nums,mid) <= threshold) r = mid-1;
            else l = mid+1;
        }
        return l;
    }

    int sumOfDiv(vector<int>& nums, int div){
        int sum = 0;
        for(int ele : nums){
            sum += (ele+div-1)/div;
        }
        return sum;
    }
};