class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> count;
        int mx = 1;
        for(int num : nums){
            count[num]++;
            mx = max(mx,count[num]);
        }
        int resp = 0;
        for(auto pair : count){
            if(pair.second == mx) resp += mx;
        }
        return resp;
    }
};