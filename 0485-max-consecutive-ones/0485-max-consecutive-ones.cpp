class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int resp = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                cnt = 0;
            }
            else{
                cnt++;
                resp=max(resp,cnt);
            }
        }
        return resp;
    }
};