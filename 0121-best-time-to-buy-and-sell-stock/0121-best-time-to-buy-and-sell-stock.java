class Solution {
    public int maxProfit(int[] prices) {
        int mi = prices[0];
        int maxProfit = 0;
        for(int i=1;i<prices.length;i++){
            mi = Math.min(mi,prices[i]);
            maxProfit = Math.max(maxProfit,prices[i]-mi);
        }
        return maxProfit;
    }
}