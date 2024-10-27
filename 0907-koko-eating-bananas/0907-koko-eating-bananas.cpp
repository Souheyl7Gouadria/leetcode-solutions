class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int mid = (l+r)>>1;
        int resp = r;
        while(l<=r){
            mid = (l+r)>>1;
            long long cnt=0;
            for(int i=0;i<n;i++){
                cnt+=(long long)(piles[i]+mid-1)/mid;
            }
            if(cnt<=h){
                r=mid-1;
                resp=mid;
            }else{
                l=mid+1;
            }
        }
        return resp;
    }
};