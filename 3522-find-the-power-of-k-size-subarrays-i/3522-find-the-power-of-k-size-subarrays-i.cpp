class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector <int> resp;
        for(int i=0;i<=nums.size()-k;i++){
            vector <int> vec(k);
            vec[0]=nums[i];
            for(int i=1;i<k;i++){
                vec[i] = vec[i-1]+1; 
            }
            // set<int> st(nums.begin()+i,nums.begin()+i+k);
            // vector<int> vec = {st.begin(),st.end()};
            vector<int> subVec(nums.begin() + i, nums.begin() + i + k);
            if (vec == subVec){
                resp.push_back(vec[k-1]);
            }else{
                resp.push_back(-1);
            }
        }
        return resp;
    }
};