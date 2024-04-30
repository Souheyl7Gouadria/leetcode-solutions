class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> resp(n+1);
        for(int i=0;i<=n;i++){
            int cnt = 0;
            for(int j=31;j>=0;j--){
                if((i&(1<<j)) != 0){
                    cnt++;
                }
            }
            resp[i]=cnt;
        }
        return resp;
    }
};