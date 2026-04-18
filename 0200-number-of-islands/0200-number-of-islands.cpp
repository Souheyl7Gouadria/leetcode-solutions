class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }

    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = true;
        vector<int> deltaRow = {-1,0,1,0};
        vector<int> deltaCol = {0,1,0,-1};

        int nR,nC;
        for(int i=0;i<4;i++){
            nR = row+deltaRow[i];
            nC = col+deltaCol[i];
            if(nR>=0 && nR <n && nC >=0 && nC <m && grid[nR][nC] == '1' && !vis[nR][nC]){
                dfs(nR,nC,vis,grid);
            } 
        }

    }
};