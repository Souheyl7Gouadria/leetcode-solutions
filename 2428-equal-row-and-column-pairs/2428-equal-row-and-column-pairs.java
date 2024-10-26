class Solution {
    public int equalPairs(int[][] grid) {
        int n = grid.length;
        int cnt = 0;
        for(int i=0;i<n;i++){
            int[] col = new int[n];
            for(int j=0;j<n;j++){
                col[j] = grid[j][i];
            }
            for(int j=0;j<n;j++){
                if(Arrays.equals(col,grid[j])) cnt++;
            }
        }
        return cnt;
    }
}