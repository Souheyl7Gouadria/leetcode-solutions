class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string ele : tokens){
            if(ele == "+" || ele == "-" || ele == "*" || ele == "/"){

                int elementOne = st.top(); st.pop();
                int elementTwo = st.top(); st.pop();

                if(ele =="+"){
                    st.push(elementTwo+elementOne);
                }
                else if(ele =="-"){
                    st.push(elementTwo-elementOne);
                }
                else if(ele =="*"){
                    st.push(elementTwo*elementOne);
                }
                else if(ele =="/"){
                    st.push(elementTwo/elementOne);
                }
            }else{
                st.push(stoi(ele));
            }
        }
        return st.top();
    }
};