class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        // 0:free, 1:guard, 2:wall, 3:guardable
        for(auto v : guards) matrix[v[0]][v[1]] = 1;
        for(auto v : walls) matrix[v[0]][v[1]] = 2;
        
        for(auto v : guards) markGuarded(matrix,v[0],v[1]);
        int resp = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!matrix[i][j]) resp++;
            }
        }
        return resp;
    }
    void markGuarded(vector<vector<int>>& matrix,int r, int c){
        int m = matrix.size();
        int n = matrix[0].size();
        // up
        for(int row = r-1; row >=0; row--){
            if(matrix[row][c] == 1 || matrix[row][c] == 2) break;
            matrix[row][c] = 3;
        }
        // down
        for(int row = r+1 ;row < m; row++){
            if(matrix[row][c] == 1 || matrix[row][c] == 2) break;
            matrix[row][c] = 3;
        }
        // left
    for(int col = c-1; col >= 0; col--){
            if(matrix[r][col] == 1 || matrix[r][col] == 2) break;
            matrix[r][col] = 3;
        }
        // right
        for(int col = c+1; col < n; col++){
            if(matrix[r][col] == 1 || matrix[r][col] == 2) break;
            matrix[r][col] = 3;
        }
    }
};