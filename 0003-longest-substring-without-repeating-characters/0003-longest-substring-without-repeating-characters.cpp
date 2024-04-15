class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        set <int> st;
        int l = 0;
        int r = 0;
        int resp = 0;
        while(r<n){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            r++;
            resp = max(resp,r-l);
        }
        return resp;
    }
};