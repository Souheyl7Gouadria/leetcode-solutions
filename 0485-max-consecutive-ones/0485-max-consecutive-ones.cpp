class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int resp = 0;
        int cnt = 0;
        for(int ele : nums){
            if(ele){
                cnt ++;
                resp = max(resp, cnt);
            }else{
                cnt = 0;
            }
        }
        return resp;
    }
};