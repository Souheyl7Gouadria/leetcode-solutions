class Solution {
public:
    int countOdds(int low, int high) {
        // count how many odd numbers are in range 0:high
        // count how many odd numbers are in range 0:low-1
        return (high+1)/2 - (low/2);
    }
};