class Solution {
    public int solve(int i,int j1,int j2,int m,int n,int[][]grid,int[][][] dp){
        if(j1<0 || j1>=n || j2<0 || j2>=n){
            return 0;
        }
        if(i==m-1){
            if(j1==j2){
                return dp[i][j1][j2]=grid[i][j1];
            }else return dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int maxi=Integer.MIN_VALUE;
        for(int d1=-1;d1<=1;d1++){
            for(int d2=-1;d2<=1;d2++){
                if(j1==j2){
                    maxi=Math.max(maxi,grid[i][j1]+solve(i+1,j1+d1,j2+d2,m,n,grid,dp));
                }else{
                    maxi=Math.max(maxi,grid[i][j1]+grid[i][j2]+solve(i+1,j1+d1,j2+d2,m,n,grid,dp));
                }
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    public int cherryPickup(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int[][][] dp = new int[m][n][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                Arrays.fill(dp[i][j],-1);
            }
        } 
        return solve(0,0,n-1,m,n,grid,dp);
    }
}