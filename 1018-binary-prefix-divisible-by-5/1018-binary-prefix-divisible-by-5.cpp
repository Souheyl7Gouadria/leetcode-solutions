class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int remainder = 0;
        vector<bool> result;
        for (int& val : nums){
            remainder = ((remainder << 1) + val) % 5;
            if (remainder == 0) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};