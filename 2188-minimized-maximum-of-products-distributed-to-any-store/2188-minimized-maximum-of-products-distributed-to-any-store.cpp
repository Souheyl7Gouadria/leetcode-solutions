class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int r = *max_element(quantities.begin(),quantities.end());
        int l = 1;
        int ans = r;
        while(l<=r){
            int mid = l+(r-l)/2;
            int res = 0;
            for(int i=0;i<m;i++){
                res+=(quantities[i]+mid-1)/mid;
                if(res>n) break;
            }
            if(res>n){
                l=mid+1;
            }else{
                ans = mid;
                r=mid-1;
            }
        }
        return ans;
    }
};