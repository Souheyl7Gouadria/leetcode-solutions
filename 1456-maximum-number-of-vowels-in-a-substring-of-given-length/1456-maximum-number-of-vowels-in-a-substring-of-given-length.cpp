class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        vector <int> v(n);
        v[0] = isVow(s[0]);
        for(int i=1;i<n;i++){
            v[i]=v[i-1]+isVow(s[i]);
        }
        int resp = v[k-1];
        for(int i=1;i<=n-k;i++){
            resp = max(resp,v[k+i-1]-v[i-1]);
        }
        return resp;
    }
public: 
    int isVow(char c){
        if(c == 'a'||c == 'e'||c == 'i'||c == 'u'||c == 'o') return 1;
        return 0;
    } 
};