class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int resp = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] == false){
                    resp += bfs(i,j,vis,grid);
                }
            }
        }
        return resp;
    }

    int bfs(int row, int col, vector<vector<bool>> &vis, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = true;

        int perim = 0;
        vector<int> deltaRow = {-1,0,1,0};
        vector<int> deltaCol = {0,-1,0,1};

        while(!q.empty()){
            pair<int,int> current = q.front();
            q.pop();
            int nR,nC;
            for(int i=0;i<4;i++){
                nR = current.first+deltaRow[i];
                nC = current.second+deltaCol[i];
                if(nR<0 || nR>=n || nC<0 || nC>=m || grid[nR][nC] == 0) perim++;
                else if(!vis[nR][nC]){
                    vis[nR][nC] = true;
                    q.push({nR,nC});
                }
            }
        }
        return perim;
    }





    int dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        // out of grid or inside grid but in water
        if(row<0 || row>=n || col<0 || col>=m || (row>=0 && row<n && col>=0 && col<m && grid[row][col] == 0)) return 1;
    
        if(vis[row][col] == 1) return 0;

        vis[row][col] = 1;
        return dfs(row+1,col,vis,grid) + dfs(row-1,col,vis,grid) + dfs(row,col+1,vis,grid) + dfs(row,col-1,vis,grid);

    }
};