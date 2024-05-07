class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zeroCnt = 0;
        int prod = 1;
        for(int ele : nums){
            if(ele !=0){
                prod*=ele;
            }else{
                zeroCnt++;
            }
        }
        vector <int> resp(n);
        for(int i=0;i<n;i++){
            if(zeroCnt >1){
                resp[i] = 0;
            }else if(zeroCnt == 1){
                if(nums[i] == 0){
                    resp[i] = prod;
                }else{
                    resp[i] = 0;
                }
            }else{
                resp[i] = prod/nums[i];
            }
        }
        return resp;
    }
};