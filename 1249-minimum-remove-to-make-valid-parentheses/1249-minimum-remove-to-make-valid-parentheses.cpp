class Solution {
public:
    string minRemoveToMakeValid(std::string s) {
        string resp = "";
        string temp = "";
        int cnt = 0;
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            if(s[i] != ')' && s[i] != '(') {
                temp += s[i];
            } else if(s[i] == ')') {
                if(cnt > 0) {
                    cnt--;
                    temp += s[i];
                }
            } else {
                cnt++;
                temp += s[i];
            }
        }
        for(int i = temp.size() - 1; i >= 0; i--) {
            if(temp[i] == '(' && cnt > 0) {
                cnt--;
            } else {
                resp += temp[i];
            }
        }
        reverse(resp.begin(), resp.end());    
        return resp;
    }
};