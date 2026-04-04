class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <int> st;
        int n = s.size();
        int r = 0;
        int l = 0;
        int resp = 0;
        while(r<n){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            r++;
            int x = st.size();
            resp = max(resp,x);
        }
        return resp;
    }
};