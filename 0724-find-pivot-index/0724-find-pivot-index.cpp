class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector <int> right(n);
        right[n-1]=nums[n-1];
        vector <int> left(n);
        left[0] = nums[0];
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+nums[i];
        }
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            if(left[i] == right[i]){
                return i;
            }
        }
        return -1;
    }
};