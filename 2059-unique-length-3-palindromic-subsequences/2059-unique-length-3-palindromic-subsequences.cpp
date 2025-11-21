class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char, pair<int,int>> pos;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (pos.find(c) == pos.end())
                pos[c] = {i, i};
            else
                pos[c].second = i;
        }

        int resp = 0;
        for (auto &p : pos) {
            int L = p.second.first;
            int R = p.second.second;

            unordered_set<char> between;

            for (int i = L+1; i < R; i++) {
                between.insert(s[i]);
            }
            resp += between.size();
        }
        return resp;
    }
};