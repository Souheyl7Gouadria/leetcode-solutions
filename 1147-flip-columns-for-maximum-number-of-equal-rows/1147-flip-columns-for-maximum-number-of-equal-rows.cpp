class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string, int> patternCount; 
        int maxRows = 0;

        for (const auto& row : matrix) {
            string pattern = "";        
            string invertedPattern = ""; 
            
            for (int val : row) {
                pattern += to_string(val);
                invertedPattern += to_string(1 - val);
            }
            
            patternCount[pattern]++;
            maxRows = max(maxRows, patternCount[pattern]);

            patternCount[invertedPattern]++;
            maxRows = max(maxRows, patternCount[invertedPattern]);
        }

        return maxRows;
    }
};
