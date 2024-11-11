class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector <bool> isPrime(1001,true);
        vector <int> primes;
        isPrime[0]=isPrime[1] = false;

        // sieve algo
        for(int i=2;i*i<=1000;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=1000;j+=i){
                    isPrime[j] = false;
                }
            }
        }
        // list of all primes < 1000
        for(int i=2;i<=1000;i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }
        int prev = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= prev) {
                return false;
            }
            auto it = lower_bound(primes.begin(), primes.end(), nums[i] - prev);
            int ixd = it - primes.begin() - 1;
            if (ixd != -1) {
                nums[i] -= primes[ixd];
            }
            prev = nums[i];
        }
        return true;
    }
};