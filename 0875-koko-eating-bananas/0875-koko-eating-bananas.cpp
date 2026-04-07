class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r=0;
        for(int ele : piles){
            r = max(r,ele);
        }
        int resp = r;
        int mid;
        long long cntH;
        while(l <= r){
            mid = (r-l)/2 + l;
            cntH = 0;
            for(int ele : piles){
                cntH += (ele+mid-1)/mid;
                if (cntH > h) break;
            }
            if(cntH > h) l = mid+1;
            else {
                resp = mid;
                r = mid-1;
            }
        }
        return resp;
    }
};