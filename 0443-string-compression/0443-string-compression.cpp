class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int l = 0;
        int k = 0;
        int r = 0;

        while (r < n) {
            while (r < n && chars[l] == chars[r]) {
                r++;
            }
            chars[k++] = chars[l];
            int count = r - l;
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[k++] = c;
                }
            }
            l = r;
        }
        return k;
    }
};
