class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n != m) return false;
        unordered_map<char,int> mp1,mp2;
        for(char c : word1){
            mp1[c]++;
        }
        for(char c : word2){
            mp2[c]++;
        }
        for(auto m : mp1){
            if(mp2[m.first] == 0) return false;
        }
        for(auto m : mp2){
            if(mp1[m.first] == 0) return false;
        }
        vector<int> occ1,occ2;
        for(auto m : mp1) occ1.push_back(m.second);
        for(auto m : mp2) occ2.push_back(m.second);
        sort(occ1.begin(),occ1.end());
        sort(occ2.begin(),occ2.end());
        return occ1 == occ2;
    }
};