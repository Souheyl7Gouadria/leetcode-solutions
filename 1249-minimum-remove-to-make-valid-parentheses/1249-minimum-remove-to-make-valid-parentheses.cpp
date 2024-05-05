class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        int close = 0;
        stack <int> st;
        for(int i=0;i<s.size();i++){
            if(s[i] !='(' && s[i] != ')'){
                st.push(s[i]);
            }else if(s[i] == '('){
                open++;
                st.push(s[i]);
            }else if(open>0){
                open--;
                st.push(s[i]);
            }
        }
        string resp = "";
        while(!st.empty()){
            char c = st.top();
            st.pop();
            if(c != '(' && c != ')'){
                resp+=c;
            }else if(c == ')'){
                close++;
                resp+=c;
            }else if(close > 0){
                resp+=c;
                close--;
            }
        }
        reverse(resp.begin(),resp.end());
        return resp;
        
    }
};