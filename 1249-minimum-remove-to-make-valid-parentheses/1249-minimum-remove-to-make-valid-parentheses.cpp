class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp = "";
        string resp = "";
        int open = 0, close = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] != '(' && s[i] != ')'){
                temp+=s[i];
            }else if(s[i] == '('){
                temp+=s[i];
                open++;
            }else if(open>0){
                temp+=s[i];
                open--;
            }
        }
        for(int i=temp.size()-1;i>=0;i--){
            if(temp[i] != '(' && temp[i] != ')'){
                resp+=temp[i];
            }else if(temp[i] == ')'){
                resp+=temp[i];
                close++;
            }else if(close>0){
                resp+=temp[i];
                close--;
            }
        }
        reverse(resp.begin(),resp.end());
        return resp;
    }
};