class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> intervals; // start position, arrival time
        for (int i=0;i<n;i++){
            intervals.push_back(make_pair(position[i],(double)(target-position[i])/speed[i]));
        }
        sort(intervals.begin(),intervals.end());

        int count = 1;
        pair<int,double> carCausingFleet = intervals[n-1];
        for (int i=n-2;i>=0;i--){
            if (intervals[i].second > carCausingFleet.second){
                count++;
                carCausingFleet = intervals[i];
            }
        }
        return count;
    }
};