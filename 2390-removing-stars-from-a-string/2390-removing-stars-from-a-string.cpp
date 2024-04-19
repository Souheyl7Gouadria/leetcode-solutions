class Solution {
public:
    string removeStars(string s) {
        stack <char> st;
        for(auto c : s){
            // we wont encounter a * if st is empty
            if(c == '*'){
                st.pop();
            }else{
                st.push(c);
            }
        }
        string resp = "";
        while(!st.empty()){
            resp+=st.top();
            st.pop();
        }
        reverse(resp.begin(),resp.end());
        return resp;
    }
};