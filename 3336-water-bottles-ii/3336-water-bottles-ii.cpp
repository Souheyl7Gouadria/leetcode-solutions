class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int resp = numBottles;
        while(numBottles >= numExchange){
            numBottles -= numExchange;
            numExchange++;
            numBottles++;
            resp++;
        }
        return resp;
    }
};