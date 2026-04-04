class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int j;
        for(int i=0;i<=n-m;i++){
            if(haystack[i] == needle[0]){
                for(j=0;j<m;j++){
                    if(haystack[i+j] != needle[j]){
                        break;
                    }
                }
                if(j == needle.size()) return i;
            }
        }
        return -1;
    }
};