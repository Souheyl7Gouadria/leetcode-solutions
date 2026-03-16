class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=1;i<=nums.size();i++) mp[i]++;

        for(auto ele : nums){
            mp[ele]--;
        }

        int duplicate = 0, missing = 0;

        for(auto ele : mp){
            if(ele.second == 1) missing = ele.first;
            if(ele.second == -1) duplicate = ele.first;
        }

        return {duplicate,missing};
    }
};