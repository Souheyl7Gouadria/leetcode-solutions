class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> front(n),back(n);
        front[0] = nums[0];
        back[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            front[i] = front[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            back[i] = back[i+1]*nums[i];
        }
        nums[0] = back[1];
        nums[n-1] = front[n-2];
        for(int i=1;i<n-1;i++){
            nums[i] = back[i+1]*front[i-1];
        }
        return nums;
    }
};