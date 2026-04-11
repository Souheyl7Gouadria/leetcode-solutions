class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        long long mid;
        while(l <= r){
            mid = l+(r-l)/2;
            if(mid*mid <= x) l = (int)mid+1;
            else r = (int)mid-1;
        }
        return l-1;
    }
};