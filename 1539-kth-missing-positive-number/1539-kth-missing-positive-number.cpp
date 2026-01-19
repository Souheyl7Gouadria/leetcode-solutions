class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cur = k;
        int i = 0;
        while(i < arr.size() && cur >= arr[i]){
            cur++;
            i++;
        }
        return cur;
    }
};