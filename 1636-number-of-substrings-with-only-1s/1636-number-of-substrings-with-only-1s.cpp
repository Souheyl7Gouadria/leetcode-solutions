static const long long MOD = 1000000007LL;

class Solution {
public:

    int numSub(string s) {
        s += '0';
        long long cnt = 0;
        long long res = 0;

        for (char c : s) {
            if (c == '1') {
                cnt++;
            } else {
                res += (cnt * (cnt + 1) / 2) % MOD;
                cnt = 0;
            }
        }
        return res;
    }
};
