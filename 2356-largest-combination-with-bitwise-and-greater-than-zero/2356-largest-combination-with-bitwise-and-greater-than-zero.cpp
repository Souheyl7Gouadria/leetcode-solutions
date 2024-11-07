class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        map<int,int> mp;
        int resp = 0;
        for(int i=0;i<candidates.size();i++){
            for(int j=0;j<32;j++){
                if((1<<j)&candidates[i]){
                    mp[j]++;
                    resp = max(resp,mp[j]);
                }
            }
        }
        return resp;
    }
};