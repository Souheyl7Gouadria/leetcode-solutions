class Solution {
public:
    bool checkValidString(string s) {
        stack <int> open;
        stack <int> stars;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                open.push(i);
            }else if(s[i] == '*'){
                stars.push(i);
            }else{
                if(!open.empty()){
                    open.pop();
                }else if(!stars.empty()){
                    stars.pop();
                }else{
                    return false;
                }
            }
        }
        while(!open.empty()){
            if(!stars.empty()){
                if(open.top()>stars.top()){
                    return false;
                }else{
                    open.pop();
                    stars.pop();
                }
            }else{
                return false;
            }
        }
        return true;
    }
};