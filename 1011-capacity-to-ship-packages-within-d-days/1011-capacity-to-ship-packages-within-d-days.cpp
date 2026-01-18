class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(),0);
        int mid;
        while(l <= r){
            mid = l+(r-l)/2;
            if(nbDays(weights, mid) <= days) r = mid-1; // reduce the capacity to get a bigger number of days
            else l = mid+1; // add capacity to get lesser number of days
        }
        return l;
    }

    int nbDays(vector<int>& weights, int capacity){
        int days = 1, load = 0;
        for(int i=0; i<weights.size();i++){
            if(load + weights[i] <= capacity){
                load += weights[i];
            }else{
                days++;
                load = weights[i];
            }
        }
        return days;
    }
};