class Solution {
public:
    int maxOperations(vector<int>& nums, int s) {
        unordered_map <int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int resp = 0;
        for (auto &[k, v] : mp) {
            int target = s - k;
            if (target == k) {
                resp += v / 2;
            } else if (mp.count(target)) {
                int pairs = min(v, mp[target]);
                resp += pairs;
                mp[k] -= pairs;
                mp[target] -= pairs;
            }
        }
        return resp;
    }
};