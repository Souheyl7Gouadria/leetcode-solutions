class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size(), m = nums2.size();
        vector<int> resp;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int i=0,j=0;
        while(i<n && j < m){
            if(nums1[i] == nums2[j]){
                if(resp.empty() || resp.back() != nums1[i]) resp.push_back(nums1[i]);
                i++;j++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }else{
                i++;
            }
        }
        return resp;
    }
};