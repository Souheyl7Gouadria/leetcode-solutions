class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]+=nums2.size();
        }
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]+=nums1.size();
        }
        int resp = 0;
        for(auto [k,v] : mp){
            if(v%2){
                resp = resp^k;
            }
        }
        return resp;
    }
};