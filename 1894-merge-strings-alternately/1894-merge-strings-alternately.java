class Solution {
    public String mergeAlternately(String word1, String word2) {
        int i = 0;
        StringBuilder resp = new StringBuilder();
        while(i<word1.length() && i<word2.length()){
            resp.append(word1.charAt(i));
            resp.append(word2.charAt(i));
            i++;
        }
        while(i<word1.length()){
            resp.append(word1.charAt(i));
            i++;
        }
        while(i<word2.length()){
            resp.append(word2.charAt(i));
            i++;
        }
        return resp.toString();
    }
}