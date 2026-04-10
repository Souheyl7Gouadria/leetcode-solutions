class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];// will have 2 statuses ; 0 & 2
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }else{
                    vis[i][j] = 0;
                }
            }
        }

        int time = 0;
        int deltaRow[] = {-1,0,1,0};
        int deltaCol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time,t);
            q.pop();
            int newRow,newCol;
            for(int i=0;i<4;i++){
                newRow = r+deltaRow[i];
                newCol = c+deltaCol[i];
                if(newRow >=0 && newRow < n && newCol >=0 && newCol <m
                    && vis[newRow][newCol] == 0 && grid[newRow][newCol] == 1){//not visited and fresh
                    q.push({{newRow,newCol},t+1});
                    vis[newRow][newCol] = 2; // now rotted
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){//it was fresh and its not rotten in the end
                    return -1;
                }
            }
        }
        return time;
    }
};