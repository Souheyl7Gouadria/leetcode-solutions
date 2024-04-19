class Solution {
public:
    int equalPairs(vector<vector<int>>& rows) {
        int n = rows.size();
        vector <vector<int> > cols;
        for(int i=0;i<n;i++){
            vector <int> col;
            for(int j=0;j<n;j++){
                col.push_back(rows[j][i]);
            }
            cols.push_back(col);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(rows[i] == cols[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};