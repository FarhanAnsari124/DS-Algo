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
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int o_j = dp[i-1];
            int t_j=0;
            if(i>1){
                t_j = dp[i-2];
            }
            dp[i] = o_j +t_j;
        }
        return dp[n];
    }
}