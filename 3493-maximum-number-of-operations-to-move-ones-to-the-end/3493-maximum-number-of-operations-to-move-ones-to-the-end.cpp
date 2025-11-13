class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        vector<int> zeroSequenceCount(n);
        int cnt = 0;
        bool inZeroSegment = false;
        for(int i=0;i<n;i++){
            if (s[i] == '0'){
                inZeroSegment = true;
            }else{
                if (inZeroSegment) cnt++;
                inZeroSegment = false;
            }
            zeroSequenceCount[i] = cnt;
        }

        if (inZeroSegment) {
            for (int i = n - 1; i >= 0 && s[i] == '0'; i--) {
                zeroSequenceCount[i] = cnt + 1;
            }
        }

        int operationsCount = 0;
        for (int i=0;i<n;i++){
            if (s[i] == '1') operationsCount+= zeroSequenceCount[n-1]-zeroSequenceCount[i];
        }
        return operationsCount;
    }
};