class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        int resp = nums[k-1];
        for(int i=k;i<n;i++){
            resp = max(resp,nums[i]-nums[i-k]);
        }
        return (double)resp/k;
    }
};