class Solution {
public:
    string simplifyPath(string path) {
        stack <string> st;
        for(int i=0;i<path.size();i++){
            if(path[i] == '/'){
                continue;
            }
            string temp = "";
            while(i<path.size() && path[i] != '/'){
                temp+=path[i];
                i++;
            }
            if(temp == "."){
                continue;
            }else if(temp == ".."){
                if(!st.empty()){
                    st.pop();
                }
                // if we get ".." and the stack is empty , nthing to do
            }else{
                st.push(temp);
            }
        }
        string route = "";
        while(!st.empty()){
            route=st.top()+'/'+route;
            st.pop();
        }
        string resp = route.substr(0,route.size()-1);
        resp = "/"+resp;
        return resp;
    }
};