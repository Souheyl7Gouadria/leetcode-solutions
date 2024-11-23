class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        for(int i=0;i<n;i++){
            int l = m-2;
            int r = m-1;
            while(l>=0){
                if(box[i][r]=='.'){
                    if(box[i][l]=='#'){
                        swap(box[i][l],box[i][r]);
                        // r=l;
                        // l=r-1;
                        r--;
                        l=r-1;
                    }else if(box[i][l] =='.'){
                        l--;
                    }else{
                        // l-=2;
                        // r=l+1;
                        r=l-1;
                        l=r-1;
                    }
                }
                else{
                    r--;
                    l=r-1;
                }
            }
        }
        vector<vector<char>> resp(m,vector<char>(n));
        for(int i=0;i<m;i++){
            vector<char> subResp;
            for(int j=n-1;j>=0;j--){
                subResp.push_back(box[j][i]);
            }
            resp[i]=subResp;
        }
        return resp;
    }
};