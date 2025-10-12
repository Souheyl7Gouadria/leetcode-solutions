// THIS solution will give TLE

// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         while(tokens.size() > 1){
//             for(int i=0;i<tokens.size();i++){
//                 if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
//                     int a = stoi(tokens[i-2]);
//                     int b = stoi(tokens[i-1]);
//                     int calc = 0;
//                     if(tokens[i] == "+") calc = a+b;
//                     if(tokens[i] == "-") calc = a-b;
//                     if(tokens[i] == "*") calc = a*b;
//                     if(tokens[i] == "/") calc = a/b;

//                     tokens.erase(tokens.begin()+i-2,tokens.begin()+i+1);
//                     tokens.insert(tokens.begin()+i-2,to_string(calc));
//                     break;
//                 }
//             }
//         }
//         return stoi(tokens[0]);
//     }
// };

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const string& c : tokens){
            if( c == "+"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b+a);
            } else if( c == "-"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b-a);
            } else if( c == "*"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b*a);
            } else if( c == "/"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b/a);
            }else{
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};
