class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=n/2;i>=1;i--){
            if(n%i == 0){
                string part = s.substr(0,i);
                string possible = "";
                int repeats = n/i;
                while(repeats--){
                    possible+=part;
                }
                if(s == possible) return true;
            }
        }
        return false;
    }
};