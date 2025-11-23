class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int maxSum = 0;
        int SmallestSumWithRemainderOne = 1e5;
        int SmallestSumWithRemainderTwo = 1e5;

        for (int i = 0; i<nums.size(); i++){
            maxSum+= nums[i];
            if (nums[i]%3 == 1){
                SmallestSumWithRemainderTwo = min(SmallestSumWithRemainderTwo, nums[i] + SmallestSumWithRemainderOne);
                SmallestSumWithRemainderOne = min(SmallestSumWithRemainderOne, nums[i]);
            }else if (nums[i]%3 == 2){
                SmallestSumWithRemainderOne = min(SmallestSumWithRemainderOne, nums[i] + SmallestSumWithRemainderTwo);
                SmallestSumWithRemainderTwo = min(SmallestSumWithRemainderTwo, nums[i]);
            }
        }
        if (maxSum%3 == 0) return maxSum;
        if (maxSum%3 == 1) return maxSum - SmallestSumWithRemainderOne;
        // remainder is 2
        return maxSum - SmallestSumWithRemainderTwo;
    }
};