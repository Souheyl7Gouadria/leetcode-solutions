class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int resp = 0;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                if(i%2) resp++;
            }
        }
        return resp;
    }
};