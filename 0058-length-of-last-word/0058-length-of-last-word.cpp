class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == ' '){
                if(cnt == 0) continue;
                else{
                    return cnt;
                }
            }else{
                cnt++;
            }
        }
        return cnt;
    }
};