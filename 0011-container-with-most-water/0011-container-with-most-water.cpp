class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int resp = (n-1)*min(height[0],height[n-1]);;
        while(l<r){
            int alternative = (r-l)*min(height[l],height[r]);
            resp = max(resp,alternative);
            if(height[l] > height[r]){
                r--;
            }else{
                l++;
            }
        }
        return resp;
    }
};