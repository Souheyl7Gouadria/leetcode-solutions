class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int cur = 1;
        int len = 1;
        unordered_set<int> seen;
        while(cur % k){
            if (seen.find(cur) != seen.end()) return -1; // we found that remainder before so the cycle is repeating and no integer is divisible by k
            seen.insert(cur);
            cur = 10*(cur%k)+1; // use the remainder as cur to avaoid overflow, if (x%k) = l then x%k = l%k 
            len++;
        }
        return len;
    }
};