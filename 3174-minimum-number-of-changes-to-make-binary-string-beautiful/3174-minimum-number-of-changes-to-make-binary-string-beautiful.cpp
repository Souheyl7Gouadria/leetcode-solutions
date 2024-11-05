class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int l = 0;
        int r = 1;
        int resp = 0;
        while(r<n){
            if(s[l] != s[r]){
                if((r+1)%2 == 0) resp++;
                l=r;
                r++;
            }else{
                r++;
            }
        }
        return resp;
    }
};