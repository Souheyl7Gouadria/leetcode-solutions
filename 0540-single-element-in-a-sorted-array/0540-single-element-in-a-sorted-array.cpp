class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;
        int m;
        while(l < r){
            m = l+(r-l)/2;
            if(m %2){
                if(arr[m] == arr[m-1]){
                    l = m+1;
                }else{
                    r = m;
                }
            }else{ // m even
                if(arr[m] == arr[m+1]){
                    l = m+2;
                }else{
                    r = m;
                }
            }
        }
        return arr[l];
    }
};