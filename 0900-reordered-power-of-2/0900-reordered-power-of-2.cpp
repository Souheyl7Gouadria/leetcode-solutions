class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string stringN = to_string(n);
        sort(stringN.begin(),stringN.end());
        for(int i=0;i<31;i++){
            string shiftedNumber = to_string(1<<i);
            sort(shiftedNumber.begin(),shiftedNumber.end());
            if(stringN == shiftedNumber) return true;
        }
        return false;
    }
};