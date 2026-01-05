class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsValue = INT_MAX;
        int negCount = 0;
        
        for(int i=0; i < matrix.size(); i++){
            for(int j=0; j < matrix[0].size(); j++){
                totalSum += abs(matrix[i][j]);
                if(matrix[i][j] < 0) negCount++;
                minAbsValue = min(minAbsValue,abs(matrix[i][j]));
            }
        }
        // if odd numbers count is odd, after making the others positive, one negative number will be left, make it the one with smallest absolute value
        if(negCount % 2) totalSum -= 2*minAbsValue;
        
        return totalSum;
    }
};