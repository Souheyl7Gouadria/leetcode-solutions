class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size()<numRows) return s;
        vector<vector<char>> grid(numRows);
        int index = 0;
        int step = 1;
        for(int i=0;i<s.size();i++){
            grid[index].push_back(s[i]);
            if(index == 0) step=1;
            if(index == numRows-1) step=-1;
            index+=step;
        }
        string resp = "";
        for(int i=0;i<numRows;i++){
            for(int j=0;j<grid[i].size();j++){
                resp+=grid[i][j];
            }
        }
        return resp;
    }
};