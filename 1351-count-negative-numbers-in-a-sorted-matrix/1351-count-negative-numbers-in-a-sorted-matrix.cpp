class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int resp = 0;
        int j = 0;
        for(int i = n-1; i>=0 && j<m; i--){
            if(grid[i][j] < 0){
                resp += (m-j);
            }else{
                j++;
                i++;
            }
        }
        return resp;
    }
};