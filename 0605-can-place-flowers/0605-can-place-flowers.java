class Solution {
    public boolean canPlaceFlowers(int[] arr, int n) {
        int k = arr.length;
        if(k == 1){
            if(arr[0] == 0) n--;
            if(n<=0) return true;
            else{
                return false;
            }
        }
        if(arr[0] == arr[1] && arr[0] == 0){
            arr[0] = 1;
            n--;
        }
        if(arr[k-1] == 0 && arr[k-2] == 0){
            arr[k-1] = 1;
            n--;
        }
        for(int i=1;i<k-1;i++){
            if(arr[i] == 0 && arr[i+1] == 0 && arr[i-1] == 0){
                arr[i]=k;
                n--;
            }
        }
        return n<=0;
    }
}