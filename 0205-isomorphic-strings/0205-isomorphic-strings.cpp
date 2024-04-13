class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map <char, set <char>> test1;
        unordered_map <char, set <char>> test2;
        int n = s.size();
        for(int i=0;i<n;i++){
            test1[s[i]].insert(t[i]);
            test2[t[i]].insert(s[i]);
        }
        for(auto m : test1){
            if(m.second.size()>1) return false;
        }
        for(auto m : test2){
            if(m.second.size()>1) return false;
        }
        return true;
    }
};