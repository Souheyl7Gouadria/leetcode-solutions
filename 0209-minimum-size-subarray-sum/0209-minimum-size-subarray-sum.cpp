class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int resp = INT_MAX ;
        vector <int> pref(n+1,0);
        // keep the first element of pref 0 for further implementation
        for(int i=1;i<=n;i++){
            pref[i]= pref[i-1] + nums[i-1];
        }
        for(int i=1;i<=n;i++){
            // here 
            int atLeast = target + pref[i-1];
            auto it = lower_bound(pref.begin() + i, pref.end(), atLeast);
            if (it != pref.end()) {
                int pos = it - pref.begin();
                resp = min(resp, pos - i + 1);
            }
        }
        if(resp == INT_MAX  ) return 0;
        return resp;
    }
};