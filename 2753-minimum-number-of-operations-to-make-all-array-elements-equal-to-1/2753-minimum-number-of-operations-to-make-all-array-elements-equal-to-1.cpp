class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int onesCount = 0;
        int gcd = 0;
        for (int i=0;i<n;i++){
            if (nums[i] == 1) onesCount++;
            gcd = gcdOfNumbers(gcd, nums[i]);
        }
        if (onesCount > 1) return n-onesCount;
        if (gcd > 1) return -1; // gcd of all numbers > 1, its impossible to make all numbers = 1

        // no 1 in the array, and gcd of the array is 1

        // get the shortest interval where gcd of all numbers = 1
        int numOfOperations = n;
        for (int i=0;i<n;i++){
            int gcd = 0;
            for (int j=i;j<n;j++){
                gcd = gcdOfNumbers(gcd, nums[j]);
                if (gcd == 1){
                    numOfOperations = min(numOfOperations, j-i+1);
                    break;
                }
            }
        }
        // 'numOfOperations-1' operation to make the shortest segment=1 & 'n-1'operation to make the rest of elemens=1
        return n+numOfOperations-2;
    }
    int gcdOfNumbers(int a, int b){
        int temp;
        while(b != 0){
            temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
};