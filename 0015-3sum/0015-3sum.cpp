class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set <vector<int>> st;
        for(int i =0;i<n-1;i++){
            int l = i+1;
            int r = n-1;
            while(l<r){
                int tot = nums[i]+nums[l]+nums[r];
                if(tot == 0){
                    vector <int> v ={nums[i],nums[l],nums[r]};
                    st.insert(v);
                    l++;
                    r--;
                }else if(tot >0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        vector <vector<int>> resp(st.begin(),st.end());
        return resp;
    }
};