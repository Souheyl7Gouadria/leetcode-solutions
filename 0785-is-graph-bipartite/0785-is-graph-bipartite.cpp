class Solution {
public:

    // bool bfs(int start, vector<vector<int>> &adj, vector<int> &colored){
    //     queue<int> q;
    //     q.push(start);
    //     colored[start] = 1;
    //     while(!q.empty()){
    //         int node = q.front();
    //         q.pop();
    //         for(int neighbor : adj[node]){
    //             if(colored[neighbor] == 0){
    //                 if(colored[node] == 1){
    //                     colored[neighbor] = 2;
    //                 }else{
    //                     colored[neighbor] = 1;
    //                 }
    //                 q.push(neighbor);
    //             }else if(colored[node] == colored[neighbor]){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    bool dfs(int node, int color, vector<int> &colored, vector<vector<int>> &adj){
        colored[node] = color;

        for(int neighbor : adj[node]){
            if(colored[neighbor] == 0){ // its not colored yet
                if(color == 1){
                    if(dfs(neighbor,2,colored,adj) == false) return false;
                }else if(color == 2){
                    if(dfs(neighbor,1,colored,adj) == false) return false;
                }
            }else if(colored[neighbor] == color){ // has the same color as its parent
                return false;
            }
        }
        return true;

    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colored(n);
        
        for(int i=0;i<n;i++){
            if(colored[i] == 0){
                if(dfs(i,1,colored,graph) == false){
                    return false;
                }
            }
        }
        return true;
    }
};