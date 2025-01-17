class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int start = 0;
        int end = 0;
        for(int i=0;i<derived.size();i++){
            if(derived[i]){
                end = !end;
            }
        }
        return start == end;
    }
};