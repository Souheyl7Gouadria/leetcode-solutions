class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt1 = 0;
        int cnt2 = 0;
        int resp = num1;
        while(num1>0){
            cnt1 += num1&1;
            num1 = num1>>1;
        }
        while(num2>0){
            cnt2 += num2&1;
            num2 = num2>>1;
        }
        int i = 0;
        while(cnt1 != cnt2){
            if(cnt1 > cnt2 && resp&(1<<i)){
                resp = resp^(1<<i);
                cnt1--;
            }
            if(cnt1<cnt2 && (resp&(1<<i)) == 0){
                resp = resp | (1<<i);
                cnt1++;
            }
            i++;
        }
        return resp;
    }
};