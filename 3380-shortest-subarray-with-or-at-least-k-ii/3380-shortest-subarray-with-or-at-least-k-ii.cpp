class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector <int> bitFreq(32);
        int resp = 2e5;
        int currentOR = 0;
        int l = 0;
        for(int r = 0;r<nums.size();r++){
            // calculate the frequency of bits reached with every array element
            for(int i=0;i<32;i++){
                if(nums[r] & (1<<i)) bitFreq[i]++;
            }
            // calculate the current obtained OR of all prev elements
            for(int i=0;i<32;i++){
                if(bitFreq[i]) currentOR |= (1<<i);
            }
            // after finding a valid answer , try to shrink the array from the left
            while(l<=r && currentOR >= k){
                resp = min(resp,r-l+1);
                // everytime, remove the cnt of bits added by the element at window left side
                for(int i=0;i<32;i++){
                    if(nums[l] & (1<<i)) bitFreq[i]--;
                }
                // we calculate the current OR once again, we cant just remove the bits that exist
                // in that element , because these bits may come from next elements int the segment
                currentOR=0;
                for(int i=0;i<32;i++){
                    if(bitFreq[i]) currentOR |= (1<<i);
                }
                l++;
            }
        }
        if(resp == 2e5) return -1;
        else return resp;
    }
};  