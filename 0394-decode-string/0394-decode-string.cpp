class Solution {
public:
    string decodeString(string s) {
        stack<int> reps;
        stack<string> sequences;
        string currentStr = "";
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                cnt = cnt*10+(s[i]-'0');
            }else if( s[i] == '['){
                reps.push(cnt);
                cnt = 0;
                sequences.push(currentStr);
                currentStr = "";
            }else if(s[i] == ']'){
                int k = reps.top();
                reps.pop();
                string temp = currentStr;
                currentStr = sequences.top();
                sequences.pop();
                while(k--){
                    currentStr+=temp;
                }
            }else{
                currentStr+=s[i];
            }
        }
        return currentStr;
    }
};