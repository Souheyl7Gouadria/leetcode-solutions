class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector <int> dp(n+1,0);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--){
            for(string w : wordDict){
                if(i+w.size()<=n && s.substr(i,(int)w.size()) == w){
                    dp[i]=dp[i+w.size()];
                }
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
};