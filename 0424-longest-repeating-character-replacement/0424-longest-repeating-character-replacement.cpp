class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> st(s.begin(),s.end());
        int resp = 0;
        for(char c : st){
            int l = 0, cnt = 0;
            for(int r=0;r<s.size();r++){
                if(s[r] == c) cnt++;
                
                while((r-l+1) - cnt > k){
                    if(s[l] == c) cnt--;
                    l++;
                }
                resp = max(resp,r-l+1);
            }
        }
        return resp;
    }
};