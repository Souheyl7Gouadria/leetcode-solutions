#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int id = 0;
        int n = gas.size();
        int totGas = accumulate(gas.begin(),gas.end(),0);
        int totCost = accumulate(cost.begin(),cost.end(),0);
        if(totCost>totGas) return -1;

        int tank = 0;
        int start = 0;
        for (int j = 0; j < n-1; j++) {
            tank += gas[j] - cost[j];
            if (tank < 0) {
                tank = 0;
                start = j+1;
            };
        }

        return start ;
    }
};
