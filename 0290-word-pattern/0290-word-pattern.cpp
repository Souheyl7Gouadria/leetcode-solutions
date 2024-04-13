class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector <string> words;
        string word = "";
        s+=" ";
        for(char c : s){
            if(c == ' '){
                words.push_back(word);
                word="";
            }else{
                word+=c;
            }
        }
        if(words.size() != pattern.size()){
            return 0;
        }
        map <char,set <string>> mp;
        for(int i=0;i<pattern.size();i++){
            mp[pattern[i]].insert(words[i]);
            if(mp[pattern[i]].size() > 1) return 0;
        }
        map <string,set <char>> mpp;
        for(int i=0;i<words.size();i++){
            mpp[words[i]].insert(pattern[i]);
            if(mpp[words[i]].size() > 1) return 0;
        }
        return 1;
    }
};