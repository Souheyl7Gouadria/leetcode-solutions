class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector <int> pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        int l = 1;
        int r = 1;
        int resp = 1e9;
        while(r<=n){
            int sum = pref[r]-pref[l-1];
            if(sum>=target){
                resp = min(resp,r-l+1);
                l++;
            }else{
                r++;
            }
        }
        if(resp == 1e9) resp = 0;
        return resp;
    }
};