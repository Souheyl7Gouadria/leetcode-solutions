class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector <int> resp(n,0);
        if( k == 0){
            return resp;
        }else if (k > 0){
            for(int i=0;i<n;i++){
                int sum = 0;
                for(int j=1;j<=k;j++){
                    sum+=code[(i+j)%n];
                }
                resp[i] = sum;
            }
        }else{
            for(int i=0;i<n;i++){
                int sum = 0;
                for(int j=1;j<=abs(k);j++){
                    sum+=code[(i-j+n)%n];
                }
                resp[i] = sum;
            }
        }
        return resp;
    }
};