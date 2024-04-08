class Solution {
public:
    bool checkValidString(string s) {
        int opencnt = 0;
        int closecnt = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] =='(' || s[i] =='*'){
                opencnt++;
            }else{
                opencnt--;
            }
            if(s[n-1-i] == ')' || s[n-1-i] == '*'){
                closecnt++;
            }else{
                closecnt--;
            }
            if(opencnt < 0 || closecnt < 0){
                return false;
            }
        }
        
        return true;
    }
};