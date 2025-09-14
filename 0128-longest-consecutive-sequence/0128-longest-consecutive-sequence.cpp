class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=1;
        }
        int cnt;
        int resp = 0;
        for(int element : nums){
            // if lesser element doesnt exist than this would be the start of the sequence 
            if(mp[element-1] == 0){
                int currNum = element;
                cnt = 1;
                while(mp[currNum+1] != 0){
                    currNum++;
                    cnt++;
                }
                resp = max(resp,cnt);
            }
        }
        return resp;
    }
};