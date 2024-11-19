class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        long long sum = 0;
        long long resp = 0;
        map<int,int> mp;
        while(end<nums.size()){
            int lastOcc = -1;
            if(mp.count(nums[end])) lastOcc = mp[nums[end]];
            while(lastOcc >= start || end-start+1 > k){
                sum-=nums[start];
                start++;
            }
            mp[nums[end]] = end;
            sum+=nums[end];
            if(end-start+1 == k) resp = max(resp,sum);
            end++;
        }
        return resp;
    }
};