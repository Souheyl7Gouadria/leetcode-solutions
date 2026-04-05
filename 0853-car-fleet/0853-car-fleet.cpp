class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int nbCars = position.size();
        vector<pair<int,double>> posTime;

        for(int i=0;i<nbCars;i++){
            pair<int,double> p = {position[i],(double)(target-position[i])/speed[i]};
            posTime.push_back(p);
        }
        sort(posTime.begin(),posTime.end());
        int fleetGroupsCount=1;
        pair<int,double> currentFleet=posTime[nbCars-1];

        // in reverse order; because if we start from the beginning, if a fleet happens early and its counted, it can be part of another fleet as we progress and in that case it will be counted twice 
        for(int i=nbCars-2;i>=0;i--){
            if(posTime[i].second > currentFleet.second){ // it wont overlap with it
                fleetGroupsCount++;
                currentFleet = posTime[i];
            }
        }
        return fleetGroupsCount;
    }
};
