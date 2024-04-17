class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int,int> mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]=1;
        }
        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]] == 1 || mp[nums2[i]] == -1){
                mp[nums2[i]] = -1;
            }else{
                mp[nums2[i]] = 2;
            }
        }
        vector <int> res1,res2;
        for(auto m : mp){
            if(m.second == 1){
                res1.push_back(m.first);
            }else if(m.second == 2){
                res2.push_back(m.first);
            }
        }
        return {res1,res2};
    }
};