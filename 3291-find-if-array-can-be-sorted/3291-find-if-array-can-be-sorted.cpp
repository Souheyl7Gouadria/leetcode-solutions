class Solution {
public:
    int countSetBits(int n){
        int cnt = 0;
        while(n){
            cnt+=n&1;
            n>>=1;
        }
        return cnt;
    }

    bool canSortArray(vector<int>& nums) {
        int setBits = countSetBits(nums[0]);
        int prevMax = INT_MIN;
        int currMin = nums[0];
        int currMax = nums[0];
        for(int n : nums){
            int bits = countSetBits(n);
            if(bits == setBits){
                currMin = min(currMin,n);
                currMax = max(currMax,n);
            }else{
                if(currMin < prevMax) return false;
                prevMax = currMax;
                setBits = countSetBits(n);
                currMin = n;
                currMax = n;
            }
        }
        return currMin>prevMax;
    }
};