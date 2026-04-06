class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l = 0, r = rows*cols-1;
        int mid;
        int row,col;
        while(l <= r){
            mid = (r-l)/2+l;
            row = mid/cols;
            col = mid%cols;
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target) r = mid-1;
            if(matrix[row][col] < target) l = mid+1;
        }
        return false;
    }
};