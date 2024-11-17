class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int minSubarrLen = INT_MAX;
        long long sum = 0;

        priority_queue<pair<long long ,int> ,vector<pair<long long,int>> , greater<>> pqueue;
        for(int i=0;i<n;i++){
            sum+=nums[i];

            // update shortest subarray length
            if(sum >= k){
                minSubarrLen = min(minSubarrLen,i+1);
            }
            // remove subarray from pqueue that form a valid one 
            while(!pqueue.empty() && sum-pqueue.top().first >= k ){
                // update shortest subarr length
                minSubarrLen = min(minSubarrLen,i-pqueue.top().second);
                pqueue.pop();
            }
            pqueue.emplace(sum,i);
        }
        if(minSubarrLen == INT_MAX) return -1;
        else return minSubarrLen;
    }
};