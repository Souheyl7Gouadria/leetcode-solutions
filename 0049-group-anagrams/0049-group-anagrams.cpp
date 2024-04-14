class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string> v=strs;

        for(int i=0;i<n;i++){
            sort(strs[i].begin(),strs[i].end());
        }
        map <string,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[strs[i]].push_back(i);
        }
        vector <vector <string>> resp;
        for(auto m : mp){
            vector <string> a;
            for(int k : m.second){
                a.push_back(v[k]);
            }
            resp.push_back(a);
        }
        return resp;
    }
};