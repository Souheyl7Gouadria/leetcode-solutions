class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return ;
        int last_index = n+m-1;
        while(n>0 && m>0){
            if(nums1[m-1] > nums2[n-1]){
                nums1[last_index] = nums1[m-1];
                m--;
            }else{
                nums1[last_index] = nums2[n-1];
                n--;
            }
            last_index--;
        }
        // only checking on 'n' in case 'm' reaches 0 (nums1 values are bigger)
        while(n--){
            nums1[last_index] = nums2[n];
            last_index--;
        }
    }
};