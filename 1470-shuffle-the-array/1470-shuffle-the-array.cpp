class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> resp(2*n);
        
        for(int i=0; i<n; i++){
            resp[2*i] = nums[i];
            resp[2*i + 1] = nums[n+i];
        }
        return resp;
    }
};