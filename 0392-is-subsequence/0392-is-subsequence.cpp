class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0;
        int q = 0;
        while(p<s.size()){
            if(q>=t.size()) return false;
            if(s[p] == t[q]){
                p++;q++;
            }else{
                q++;
            }
        }
        return p == s.size();
        
    }
};