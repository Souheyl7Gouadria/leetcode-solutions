class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char,int> freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        map<int,vector<char>,greater<int>> mp;
        for (auto& kv : freq) {
            mp[kv.second].push_back(kv.first);
        }
        string resp="";
        for(auto& pair : mp){
            int freq= pair.first;
            vector <char> &chars = pair.second;
            for(char c : chars){
                for (int i = 0; i < freq; ++i) {
                    resp += c;
                }
            }
        }
        return resp;
    }
};