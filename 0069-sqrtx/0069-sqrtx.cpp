class Solution {
public:
    int mySqrt(int x) {
        long long i = 0;
        while(i*i<x){
            i+=1;
        }
        if(i*i<=x) return i;
        return i-1;
    }
};