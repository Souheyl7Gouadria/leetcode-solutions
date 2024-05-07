class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> prefProd(n);
        vector <int> suffProd(n);
        prefProd[0] = nums[0];
        suffProd[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            prefProd[i]=prefProd[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suffProd[i]=suffProd[i+1]*nums[i];
        }
        vector <int> resp(n);
        resp[0]=suffProd[1];
        resp[n-1]=prefProd[n-2];
        for(int i=1;i<n-1;i++){
            resp[i] = prefProd[i-1]*suffProd[i+1];
        }
        return resp;
    }
};