class Solution {
public:
    string ans = "";
    void expand(string &s, int l , int r){
        while(l>=0 && r<s.size()){
            if(s[l] != s[r]){
                break;
            }
            l--;
            r++;
        }
        if(ans.size()<=r-l-1){
            // start from l+1 because the left pointer always goes one step further
            // decrease 1 from the length r-l because the right pointer always goes one step further
            ans = s.substr(l+1,r-l-1);
        }
    }



    string longestPalindrome(string s) {
        // expand the possible palindrome from each index because 
        for(int i=0;i<s.size();i++){
            // palindrome of odd length
            expand(s,i,i);
            // palindrome of even length
            expand(s,i,i+1);
        }
        return ans;
    }
};