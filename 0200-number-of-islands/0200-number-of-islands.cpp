class Solution {
public:

    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){

        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int deltaRow[] = {0,-1,0,1};
            int deltaCol[] = {1,0,-1,0};
            int newRow,newCol;
            for(int i = 0; i < 4; i++){
                newRow = row+deltaRow[i];
                newCol = col+deltaCol[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !vis[newRow][newCol] && grid[newRow][newCol] == '1'){
                    vis[newRow][newCol] = 1;
                    q.push({newRow,newCol});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};