class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> obsCnt(m,vector<int>(n,INT_MAX));
        obsCnt[0][0] = grid[0][0];

        //obsCnt,row,col
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq ;
        pq.push({obsCnt[0][0],0,0});
        while(!pq.empty()){
            vector<int> current = pq.top();
            pq.pop();
            int obstacles = current[0] , row = current[1] , col = current[2];
            if(row  == m-1 && col == n-1) return obstacles;
            for(vector<int>& d : dir){
                int r = row+d[0];
                int c = col+d[1];
                if(r>=0 && r<m && c>=0 && c<n){
                    int newCnt = obstacles + grid[r][c];
                    if(newCnt < obsCnt[r][c]){
                        obsCnt[r][c] = newCnt;
                        pq.push({newCnt,r,c});
                    }
                }
            }
        }
        return obsCnt[m-1][n-1];
    }
};