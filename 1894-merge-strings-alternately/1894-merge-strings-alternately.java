class Solution {
    public String mergeAlternately(String word1, String word2) {
        int i = 0;
        String resp = "";
        while(i<word1.length() && i<word2.length()){
            resp+=word1.charAt(i);
            resp+=word2.charAt(i);
            i++;
        }
        while(i<word1.length()){
            resp+=word1.charAt(i);
            i++;
        }
        while(i<word2.length()){
            resp+=word2.charAt(i);
            i++;
        }
        return resp;
    }
}