class Solution {

    // we will check for each column, does adding the letter at this index mess the order
    // if yes that column is deleted otherwise its kept
public:
    bool sorted(vector<string> arr){
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i] > arr[i+1]) return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
       int n = strs.size();
       int m = strs[0].size();
       int colsToBeDeleted = 0;

       vector<string> cur(n);
       for(int j=0;j<m;j++){
            vector<string> cur2 = cur;
            for(int i=0;i<n;i++){
                cur2[i] += strs[i][j];
            }
            if(sorted(cur2)) cur = cur2;
            else colsToBeDeleted++;
       }
       return colsToBeDeleted;
    }
};