class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> resp(n);
        stack<pair<int,int>> stack;
        for(int i=0;i<n;i++){
            int t = temperatures[i];
            while(!stack.empty() && t > stack.top().first){
                auto pair = stack.top();
                stack.pop();
                resp[pair.second] = i - pair.second;
            }
            stack.push({t,i});
        }
        return resp;
    }
};