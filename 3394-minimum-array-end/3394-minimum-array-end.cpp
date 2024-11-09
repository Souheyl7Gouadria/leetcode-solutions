class Solution {
public:
    long long minEnd(int n, int x) {
        long long resp = x;
        n--;
        while(n--){
            resp++;
            resp|=x;
        }
        return resp;
    }
};