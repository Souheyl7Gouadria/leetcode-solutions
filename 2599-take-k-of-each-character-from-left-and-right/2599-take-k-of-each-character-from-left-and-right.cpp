class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> occ(3);
        for(char c : s) occ[c-'a']++;
        if(occ[0] < k || occ[1] < k || occ[2] < k) return -1;
        int l = 0;
        int resp = INT_MAX;
        int n = s.size();
        for(int r=0;r<n;r++){
            // maximize the size of the window [l,r] so become minimal
            occ[s[r]-'a']--; 
            while(*min_element(occ.begin(),occ.end()) < k){
                occ[s[l]-'a']++;
                l++;
            }
            resp = min(resp,n-(r-l+1));
        }
        return resp;
    }
};