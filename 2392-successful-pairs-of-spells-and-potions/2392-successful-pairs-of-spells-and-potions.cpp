class Solution {
public:
    vector<int> successfulPairs(vector<int>& a, vector<int>& b, long long target) {
        int n = a.size();
        int m = b.size();
        vector <int> resp(n);
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++){
            long long l = 0;
            long long r = m-1;
            while(l<=r){
                int mid = l+(r-l)/2;
                long long val = (long long)a[i]*(long long)b[mid];
                if(val >= target){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            resp[i]=max(0LL,m-r-1);
        }
        return resp;
    }
};