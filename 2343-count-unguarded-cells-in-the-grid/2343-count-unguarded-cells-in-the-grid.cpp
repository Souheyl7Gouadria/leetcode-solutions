class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m,vector<int> (n,0)); // guard 1 , wall 2 , guarded cell 3 , not guarded 0
        for(int i=0;i<guards.size();i++){
            matrix[guards[i][0]][guards[i][1]] = 1;
        }
        for(int i=0;i<walls.size();i++){
            matrix[walls[i][0]][walls[i][1]] = 2;
        }

        auto mark = [&](int r, int c) {
            // vertically
            for(int row = r-1; row >= 0 ; row--){
                if(matrix[row][c] == 1 || matrix[row][c] == 2) break;
                matrix[row][c] = 3;
            }
            for(int row = r+1; row < m ; row++){
                if(matrix[row][c] == 1 || matrix[row][c] == 2) break;
                matrix[row][c] = 3;
            }
            // vertically
            for(int col = c-1; col >= 0 ; col--){
                if(matrix[r][col] == 1 || matrix[r][col] == 2) break;
                matrix[r][col] = 3;
            }
            for(int col = c+1; col < n ; col++){
                if(matrix[r][col] == 1 || matrix[r][col] == 2) break;
                matrix[r][col] = 3;
            }
        };

        for(int i=0;i<guards.size();i++){
            mark(guards[i][0],guards[i][1]);
        }
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
    
};