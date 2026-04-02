class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int k = 1;
        for(int ele : target){
            while(k < ele){
                operations.push_back("Push");
                operations.push_back("Pop");
                k++;
            }
            operations.push_back("Push");
            k++;
        }
        return operations;
    }
};