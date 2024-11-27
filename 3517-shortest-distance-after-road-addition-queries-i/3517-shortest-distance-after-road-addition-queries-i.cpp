class Solution {
public:

    int dfs(int n, vector<vector<int>>& queries , vector<vector<int>> adj) {
        queue<pair<int,int>> q;
        q.push({0,0});
        unordered_set<int> visit;
        while(!q.empty()) {
            int cur = q.front().first;
            int len = q.front().second;
            q.pop();
            if(cur == n-1) return len;
            for(int nei : adj[cur]) {
                if(visit.find(nei) == visit.end()){
                    q.push({nei,len+1});
                    visit.insert(nei);
                }
            }
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            adj[i].push_back(i+1);
        }
        vector<int> resp;
        for(auto q : queries){
            adj[q[0]].push_back(q[1]);
            resp.push_back(dfs(n,queries,adj));
        }
        return resp;
    }
};