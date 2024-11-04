class Solution {
public:
    string compressedString(string word) {
        int cnt = 1;
        string comp = "";
        int n = word.size();
        for(int i=1;i<n;i++){
            if(word[i]!=word[i-1] || cnt == 9){
                comp += cnt+'0';
                comp+=word[i-1];
                cnt = 1;
            }else{
                cnt++;
            }
        }
        comp+=cnt+'0';
        comp+=word[n-1];
        return comp;
    }
};