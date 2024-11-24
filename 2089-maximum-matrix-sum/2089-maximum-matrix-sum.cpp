class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        vector<long long> elements;
        int negCount = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] < 0) negCount++;
                elements.push_back(abs(matrix[i][j]));
            }
        }
        sort(elements.begin(),elements.end());
        long long sum = 0;
        negCount%=2;
        int i=0;
        if(negCount){
            sum = -elements[0];
            i = 1;
        }
        for(;i<elements.size();i++){
            sum+=elements[i];
        }
        return sum;
    }
};