class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > n) return -1;

        int l = *min_element(bloomDay.begin(),bloomDay.end());
        int r = *max_element(bloomDay.begin(),bloomDay.end());
        int mid;
        while(l<r){
            mid = l+(r-l)/2;
            if(possible(bloomDay,mid,m,k)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }

    bool possible(vector<int>& arr, int day, int m, int k){
        
        int cnt = 0;
        int nbOfBouquets = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] <= day){
                cnt++;
            }else{
                nbOfBouquets += (cnt/k);
                cnt = 0;
            }
        }
        nbOfBouquets += (cnt/k);
        if(nbOfBouquets >= m) return true;
        return false;
    }
};