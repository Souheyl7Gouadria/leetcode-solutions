class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector <int> left = nums;
        vector <int> right = nums;
        int n = nums.size();
        for(int i=1;i<n;i++){
            left[i] += left[i-1];
            right[n-i-1] += right[n-i];
        }
        for(int i=0;i<n;i++){
            if(left[i] == right[i]){
                return i;
            }
        }
        return -1;
    }
};