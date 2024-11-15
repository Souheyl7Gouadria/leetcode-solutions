class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int prefixEnd = 0;
        int suffixBegin = n-1;
         while (prefixEnd < n - 1 && arr[prefixEnd] <= arr[prefixEnd + 1]) {
            prefixEnd++;
        }
        if (prefixEnd == n - 1) return 0;

        while (suffixBegin > 0 && arr[suffixBegin - 1] <= arr[suffixBegin]) {
            suffixBegin--;
        }
        int result = min(n - prefixEnd - 1, suffixBegin);
        int i = 0, j = suffixBegin;
        while(i<=prefixEnd && j<n){
            if(arr[i]<=arr[j]){
                result = min(result,j-i-1);
                i++;
            }else{
                j++;
            }
        }
        cout<<prefixEnd<<" "<<suffixBegin;
        return result;
    }
};