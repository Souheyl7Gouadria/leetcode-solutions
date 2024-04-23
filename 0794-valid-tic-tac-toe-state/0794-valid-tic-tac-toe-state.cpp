class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int zeros = 0;
        int ones = 0;
        bool ok1=0;
        bool ok0=0;
        for(int i=0;i<3;i++){
            int zeroscol = 0;
            int zerosrow = 0;
            int onescol = 0;
            int onesrow = 0;
            for(int j=0;j<3;j++){
                if(board[i][j] =='O'){
                    zerosrow++;
                    zeros++;
                }else if(board[i][j] =='X'){
                    onesrow++;
                    ones++;
                }
                if(board[j][i] =='O'){
                    zeroscol++;
                }else if(board[j][i] =='X'){
                    onescol++;
                }
            }
            // check for rows and cols 
            if(onesrow == 3 || onescol == 3){
                ok1=1;
                // if(zeros >= ones){
                //     return false;
                // }
            }else if(zerosrow == 3 || zeroscol == 3){
                ok0=1;
                // if(ones>zeros){
                //     return false;
                // }
            }
        }
        int diagZero = 0;
        int antiDiagZero = 0;
        int diagOne = 0;
        int antiDiagOne = 0;
        for(int i=0;i<3;i++){
            diagZero += (board[i][i] == 'O');
            diagOne += (board[i][i] == 'X');
            antiDiagZero += (board[i][2-i] == 'O');
            antiDiagOne += (board[i][2-i] == 'X');
        }
        if(diagOne == 3 || antiDiagOne == 3){
            ok1=1;
            // if(zeros >= ones){
            //     return false;
            // }
        }
        if(diagZero == 3 || antiDiagZero == 3){
            ok0=1;
            // if(ones > zeros){
            //     return false;
            // }
        }
       if (zeros > ones || (ones - zeros > 1)) {
            return false;
        }
        
        if (ok1 && zeros == ones) {
            return false;
        }
        
        if (ok0 && ones > zeros) {
            return false;
        }
        
        return true;
    }
};