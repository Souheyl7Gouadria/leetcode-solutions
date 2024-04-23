class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector <int> row(9,0);
            vector <int> col(9,0);
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    int x = board[i][j]-'0'-1;
                    row[x]++;
                }
                if(board[j][i] != '.'){
                    int x = board[j][i]-'0'-1;
                    col[x]++;
                }
            }
            for(int element : row){
                if(element > 1) return false;
            }
            for(int element : col){
                if(element > 1) return false;
            }
        }
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                vector <int> square(9,0);
                for(int i=k*3;i<k*3+3;i++){
                    for(int j=l*3;j<l*3+3;j++){
                        if(board[i][j] != '.'){
                            int x = board[i][j]-'0'-1;
                            square[x]++;
                        }
                    }
                }
                for(int element : square){
                    if(element > 1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};