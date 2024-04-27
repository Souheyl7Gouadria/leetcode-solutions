class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector <int> gray;
        int idx;
        for(int i=0;i<(1<<n);i++){
            int x = i^(i>>1);
            gray.push_back(x);
            if(x == start) idx = i;
        }
        vector <int> resp;
        for(int i=idx;i<gray.size();i++){
            resp.push_back(gray[i]);
        }
        for(int i=0;i<idx;i++){
            resp.push_back(gray[i]);
        }
        return resp;
    }
};