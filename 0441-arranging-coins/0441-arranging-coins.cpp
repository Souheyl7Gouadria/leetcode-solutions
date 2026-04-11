class Solution {
public:
    int arrangeCoins(int n) {
        return (int)((-1ll + sqrtl(1+8ll*n))/2);
    }
};