class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        
        vector<vector<char>> matrix(3, vector<char>(3, '*'));
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                matrix[moves[i][0]][moves[i][1]] = 'X';
            }else{
                matrix[moves[i][0]][moves[i][1]] = 'O';
            }
        }
        int diagx = 0;
        int antix = 0;
        int diag0 = 0;
        int anti0 = 0;
        for(int i=0;i<3;i++){
            int rowx = 0;
            int colx = 0;
            int row0 = 0;
            int col0 = 0;
            diagx+=(matrix[i][i] == 'X');
            antix+=(matrix[i][2-i] == 'X');
            diag0+=(matrix[i][i] == 'O');
            anti0+=(matrix[i][2-i] == 'O');
            for(int j=0;j<3;j++){
                rowx+=(matrix[i][j] == 'X');
                colx+=(matrix[j][i] == 'X');
                row0+=(matrix[i][j] == 'O');
                col0+=(matrix[j][i] == 'O');
            }
            if(row0 == 3 || col0 == 3){
                return "B";
            }else if(rowx == 3 || colx == 3){
                return "A";
            }
        }
        if(diagx == 3 || antix == 3){
            return "A";
        }else if(diag0 == 3 || anti0 == 3){
            return "B";
        }
        if(n==9) return "Draw";
        return "Pending";
    }
};