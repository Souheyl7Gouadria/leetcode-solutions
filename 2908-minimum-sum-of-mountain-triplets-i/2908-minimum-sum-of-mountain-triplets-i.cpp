class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int resp = 150;
        bool ok = 0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]<nums[j] && nums[j]>nums[k]){
                        int x = nums[i]+nums[j]+nums[k];
                        resp = min(resp,x);
                        ok = 1;
                    }
                    
                }
            }
        }
        if(ok) return resp;
        return -1;
    }
};