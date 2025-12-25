class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(),happiness.end());
        long long resp = 0;
        for(int i=n-k;i<n;i++){
            if(happiness[i] >= n-1-i){
                happiness[i]-=(n-1-i);
            }else{
                happiness[i] = 0;
            }
            resp+=happiness[i];
        }
        return resp;
    }
};