class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0,r = n;
        long mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(mid*(mid+1)/2 <= n) l = (long)mid+1;
            else r = (long)mid-1;
        }
        return l-1;
    }
};