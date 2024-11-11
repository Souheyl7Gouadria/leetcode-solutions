class Solution {
public:
    string addBinary(string a, string b) {
        string resp = "";
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        while(i>=0 || j>=0){
            int sum=carry;
            if(i>=0) sum+=a[i--]-'0';
            if(j>=0) sum+=b[j--]-'0';
            if(sum>1) carry = 1;
            else carry = 0;

            if(sum%2) resp='1'+resp;
            else resp='0'+resp;
        }
        if(carry) resp='1'+resp;
        return resp;
    }
};