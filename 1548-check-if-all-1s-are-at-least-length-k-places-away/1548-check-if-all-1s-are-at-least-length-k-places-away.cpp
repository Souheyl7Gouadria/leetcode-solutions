class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        auto it = find(nums.begin(), nums.end(), 1);
        if (it == nums.end()) return true;
        int OneIndex = it - nums.begin();
        for (int i=OneIndex+1;i<nums.size();i++){
            if (nums[i] == 1){
                if (i-OneIndex-1 < k) return false;
                OneIndex = i;
            }
        }
        return true;
    }
};