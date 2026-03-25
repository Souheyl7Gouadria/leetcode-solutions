class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int ele : nums){
            mp[ele]++;
        }
        vector<int> resp;
        for(int i=1;i<=n;i++){
            if(mp[i] == 0) resp.push_back(i);
        }
        return resp;
    }
};