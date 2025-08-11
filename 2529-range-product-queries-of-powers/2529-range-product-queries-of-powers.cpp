class Solution {
public:
    const int MOD = 1e9 + 7;
    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powersOf2;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                powersOf2.push_back(1LL << i);
            }
        }
        int m = powersOf2.size();
        vector<long long> prefix(m);
        prefix[0] = powersOf2[0] % MOD;
        for (int i = 1; i < m; i++) {
            prefix[i] = (prefix[i-1] * powersOf2[i]) % MOD;
        }
        vector<int> result;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            if (l == 0) {
                result.push_back(prefix[r]);
            } else {
                long long inv = modPow(prefix[l-1], MOD - 2);
                result.push_back((prefix[r] * inv) % MOD);
            }
        }
        return result;
    }
};