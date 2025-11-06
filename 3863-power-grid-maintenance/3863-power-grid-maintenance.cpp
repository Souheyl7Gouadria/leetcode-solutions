class Solution {
public:
    void dfs(int node, int compId, vector<vector<int>>& adjList, vector<int>& comp) {
        comp[node] = compId;
        for (int voisin : adjList[node]) {
            if (comp[voisin] == -1)
                dfs(voisin, compId, adjList, comp);
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(c + 1);
        for (auto& p : connections) {
            adjList[p[0]].push_back(p[1]);
            adjList[p[1]].push_back(p[0]);
        }

        vector<int> components(c + 1, -1);
        int compId = 0;
        for (int i = 1; i <= c; i++) {
            if (components[i] == -1)
                dfs(i, compId++, adjList, components);
        }

        vector<set<int>> onlineNodesInComponent(compId);
        vector<bool> online(c + 1, true);
        for (int i = 1; i <= c; i++) {
            onlineNodesInComponent[components[i]].insert(i);
        }

        vector<int> resp;
        for (auto& q : queries) {
            int x = q[1];
            int componentId = components[x];
            if (q[0] == 1) {
                if (online[x]) resp.push_back(x);
                else {
                    if (onlineNodesInComponent[componentId].empty()) resp.push_back(-1);
                    else resp.push_back(*onlineNodesInComponent[componentId].begin());
                }
            } else if (q[0] == 2) {
                if (online[x]) {
                    online[x] = false;
                    onlineNodesInComponent[componentId].erase(x);
                }
            }
        }

        return resp;
    }
};