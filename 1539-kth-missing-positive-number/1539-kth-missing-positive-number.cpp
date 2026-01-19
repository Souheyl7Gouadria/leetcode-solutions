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
            if(missing < k) l = m+1;
            else r = m-1;
        }
        return k+r+1; // or k+l becaus in the end arr : ..rl.. so l = r+1;
    }
};