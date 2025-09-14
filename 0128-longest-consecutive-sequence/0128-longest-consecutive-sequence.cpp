class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> unique_numbers(nums.begin(), nums.end());
        int resp = 0;
        for(int ele : unique_numbers){
            // if lesser element doesnt exist than this would be the start of the sequence
            if(unique_numbers.find(ele-1) == unique_numbers.end()){
                int current = ele;
                int cnt=1;
                while(unique_numbers.find(current+1) != unique_numbers.end()){
                    current++;
                    cnt++;
                }
                resp = max(resp,cnt);
            }
        }
        return resp;
    }
};