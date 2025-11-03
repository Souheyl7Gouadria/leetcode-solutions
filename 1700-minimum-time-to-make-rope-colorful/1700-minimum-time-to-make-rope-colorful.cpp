class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minCost = 0;
        int maxi = 0;
        int n = neededTime.size();
        for(int i=1;i<n;i++){
            maxi = 0;
            while(i < n && colors[i] == colors[i-1]){
                minCost += neededTime[i-1];
                maxi = max(maxi, neededTime[i-1]);
                ++i;
            }
            minCost += neededTime[i-1];
            maxi = max(maxi, neededTime[i-1]);
            if(maxi != 0) minCost -= maxi;
        }
        return minCost;
    }
};