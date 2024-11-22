class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount; 
        int maxRows = 0;
        for (const auto& row : matrix) {
            string pattern = "";        
            bool startWith0 = row[0] == 0;
            
            for (int val : row) {
                if(startWith0) {
                     pattern+= to_string(val);
                }else{
                     pattern+= to_string(1 - val);
                } 
            }
            
            patternCount[pattern]++;
            maxRows = max(maxRows, patternCount[pattern]);
        }
        return maxRows;
    }
};
