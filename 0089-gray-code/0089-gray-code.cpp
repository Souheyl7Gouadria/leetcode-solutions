class Solution {
public:
    vector<int> grayCode(int n) {
        vector <int> resp;
        for(int i=0;i<(1<<n);i++){
            resp.push_back(i^(i>>1));
        }
        return resp;
    }
};