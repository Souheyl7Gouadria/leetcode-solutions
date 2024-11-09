class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map <int ,int> mp;
        for(int i=0;i<numbers.size();i++){
            mp[numbers[i]] = i;
        }
        for(int i=0;i<numbers.size();i++){
            int needed = target-numbers[i];
            if(mp[needed] && mp[needed] != i){
                return {i+1,mp[needed]+1};
            }
        }
        return {};
    }
};