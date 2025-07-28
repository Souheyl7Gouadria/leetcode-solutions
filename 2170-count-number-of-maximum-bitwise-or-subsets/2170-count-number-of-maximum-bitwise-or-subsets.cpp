class Solution {
public:
    //backtracking solution in O(n*2^n)
    void generateSubsets(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& allSubsets){
        if(index == nums.size()){
            allSubsets.push_back(subset);
            return;
        }
        //include in subset
        subset.push_back(nums[index]);
        generateSubsets(index+1,nums,subset,allSubsets);

        //exclude from subset
        subset.pop_back();
        generateSubsets(index+1,nums,subset,allSubsets);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> subset;
        generateSubsets(0,nums,subset,allSubsets);
        int numsOr=0;
        int subsetOr=0;
        int result=0;
        for(int i : nums){
            numsOr|=i;
        }
        for(int i=0;i<allSubsets.size();i++){
            for(int j=0;j<allSubsets[i].size();j++){
                subsetOr|=allSubsets[i][j];
            }
            if(subsetOr == numsOr) result++;
            subsetOr=0;
        }
        return result;
    }
};