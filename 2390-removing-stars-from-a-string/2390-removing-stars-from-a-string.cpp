class Solution {
public:
    string removeStars(string s) {
        string resp = "";
        for(char c : s){
            // a solution always exist so there will not encounter * if resp is ""
            if(c == '*'){
                resp.pop_back();
            }else{
                resp+=c;
            }
        }
        return resp;

    }
};