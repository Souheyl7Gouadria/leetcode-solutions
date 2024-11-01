class Solution {
public:
    string makeFancyString(string s) {
        int cnt = 1;
        string resp = "";
        resp+=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i] == resp.back()){
                if(cnt == 1){
                    resp+=s[i];
                    cnt++;
                }
            }else{
                resp+=s[i];
                cnt = 1;
            }
        }
        return resp;
    }
};