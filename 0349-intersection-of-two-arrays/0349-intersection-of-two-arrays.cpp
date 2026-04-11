class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(),nums1.end());
        unordered_set<int> uniqueElements;

        for(int ele : nums2){
            if(st.count(ele)){
               uniqueElements.insert(ele);
            }
        }
        return vector<int>(uniqueElements.begin(),uniqueElements.end());
    }
};