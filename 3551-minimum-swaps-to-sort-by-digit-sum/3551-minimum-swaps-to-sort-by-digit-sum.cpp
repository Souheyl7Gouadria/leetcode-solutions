class Solution {
public:

    int getDigitSum(int val){
        int sum = 0;
        while(val>0){
            sum+= val%10;
            val = val/10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        struct Element {
            int digitSum;
            int value;
            int origIndex;
        };

        vector<Element> elements(n);
        for(int i=0;i<n;i++){
            elements[i] = {getDigitSum(nums[i]),nums[i],i};
        }

        sort(elements.begin(),elements.end(), [](const Element& a, const Element&b){
            if(a.digitSum != b.digitSum){
                return a.digitSum < b.digitSum;
            }
            return a.value < b.value;
        });

        vector<bool> visited(n,false);
        int totalSwaps = 0;
        for(int i=0; i< n; i++){
            if(visited[i] || elements[i].origIndex == i) continue;
            
            int cycleSize = 0;
            int curr = i;
            while(!visited[curr]){
                visited[curr] = true;
                curr = elements[curr].origIndex;
                cycleSize++;
            }
            // a cycle of size k requires k-1 swaps
            totalSwaps += (cycleSize > 1) ? cycleSize-1 : 0;
        }
        return totalSwaps;
    }
};