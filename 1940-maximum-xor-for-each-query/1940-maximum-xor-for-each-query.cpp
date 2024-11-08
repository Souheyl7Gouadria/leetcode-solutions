class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int totXOR = 0;
        vector <int> resp;
        for(int i=0;i<nums.size();i++){
            totXOR^=nums[i];
        }
        int mask = (1<<maximumBit)-1;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            resp.push_back(totXOR^mask);
            totXOR^=nums[i];
        }
        return resp;
    }
};