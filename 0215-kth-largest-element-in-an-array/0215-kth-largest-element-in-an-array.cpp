class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(),nums.end()); // bigger elements are on top

        k--;
        while(k--){
            maxHeap.pop();
        }

        return maxHeap.top();
    }
};