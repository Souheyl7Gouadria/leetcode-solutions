class Solution {
public:
    bool isPowerOfTwo(int n) {
        // method 1: count number of set bits
        // if(__builtin_popcount(n) == 1 ) return true;
        // return false;

        // method 2: AND with n-1
        if(n>0 && ((n&(n-1)) == 0)) return true;
        return false;
    }
};