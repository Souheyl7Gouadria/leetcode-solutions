class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int total = 0;
        int balance = 0;
        for(int i=0;i<gas.size();i++){
            balance += gas[i]-cost[i];
            total += gas[i]-cost[i];
            if(balance < 0){
                start=i+1;
                balance = 0;
            }
        }
        if(total<0) return -1;
        return start;
    }
};