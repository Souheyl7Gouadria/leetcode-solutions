class Solution {
public:
    // brute forve O(n)

    // int findKthPositive(vector<int>& arr, int k) {
    //     int cur = k;
    //     int i = 0;
    //     while(i < arr.size() && cur >= arr[i]){
    //         cur++;
    //         i++;
    //     }
    //     return cur;
    // }

    // Binary search (Striver)
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0;
        int r = arr.size()-1;
        int m;
        int missing;
        while(l <= r){
            m = l+(r-l)/2;
            missing = arr[m] - (m+1);
            if(missing < k) l = m+1; // the nb of missing numbers at index m are less than k, look right
            else r = m-1; // the nb of missing numbers at index m are bigger than k, look left
        }

        // edge case
        if (r < 0) return k;

        // the missing number is between arr[r] & arr[l] (r = l-1), and it comes at arr[r] + "more = k-missing(r)"
        int more = k - (arr[r]-(r+1)); 
        return arr[r]+more;
    }
};