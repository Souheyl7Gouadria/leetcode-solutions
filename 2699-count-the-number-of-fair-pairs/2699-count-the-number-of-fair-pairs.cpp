class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long resp = 0;
        for(int i=0;i<nums.size();i++){
            int low = lower-nums[i];
            int up = upper-nums[i];
            int lessThanUp = lower_bound(nums.begin()+i+1,nums.end(),up+1)-nums.begin();
            int greatThanLow = lower_bound(nums.begin()+i+1,nums.end(),low)-nums.begin();
            resp += (lessThanUp - greatThanLow);
        }
        return resp;
    }
};