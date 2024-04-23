class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int resp = 0;
        int n = mat.size();
        for(int i=0;i<n;i++){
            resp+=(mat[i][i]+mat[i][n-1-i]);
        }
        if(n%2) resp-=mat[n/2][n/2];
        return resp;
    }
    
};