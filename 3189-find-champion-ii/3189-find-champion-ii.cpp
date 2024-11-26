class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][1]]++;
        }
        int cnt = 0;
        int resp = -1;
        for(int i=0;i<n;i++){
            if(mp[i] == 0){
                cnt++;
                resp = i;
            }
        }
        if(resp == -1 || cnt > 1) return -1;
        else return resp;
    }
};