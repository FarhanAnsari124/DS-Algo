class Solution {
    public int f(int n,int[] dp){
        if(n==0){
            return dp[n]=1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int o_j = f(n-1,dp);
        int t_j = f(n-2,dp);
        return dp[n]=o_j+t_j;
    }
    public int climbStairs(int n) {
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        int a=f(n,dp);
        return dp[n];
    }
}