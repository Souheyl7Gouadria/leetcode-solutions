class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char,char> mp1;
        for(int i=0;i<s.length();i++){
            mp1[s[i]]=t[i];
        }
        string test1 = "";
        for(int i=0;i<s.length();i++){
            test1+=mp1[s[i]];
        }
        unordered_map <char,char> mp2;
        for(int i=0;i<s.length();i++){
            mp2[t[i]]=s[i];
        }
        string test2 = "";
        for(int i=0;i<s.length();i++){
            test2+=mp2[t[i]];
        }
        return test1 == t && test2 == s;
    }
};