class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int l = 0;
        int r = 1;
        vector <char> resp;
        while(r<n){
            if(chars[l] != chars[r]){
                resp.push_back(chars[l]);
                getDigitsFromCnt(l,r,resp);
                l=r;
            }
            r++;
        }
        resp.push_back(chars[l]);
        getDigitsFromCnt(l,r,resp);
        chars = resp;
        return chars.size();
    }
    void getDigitsFromCnt(int l,int r, vector<char> &resp){
        string cnt = to_string(r-l);
        if(cnt == "1") return ;
        for(char c : cnt){
            resp.push_back(c);
        }
    }
};