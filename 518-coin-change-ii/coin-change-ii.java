class Solution {
    public int solve(int i,int sum,int n,int[]coins,int[][]dp){
        if(i>=n){
            return 0;
        }
        if(i==n-1){
            if(sum%coins[i]==0){
                return dp[i][sum]=1;
            }else{
                return dp[i][sum]=0;
            }
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int take=0;
        if(coins[i]<=sum){
            take=solve(i,sum-coins[i],n,coins,dp);
        }
        int not_take=solve(i+1,sum,n,coins,dp);
        return dp[i][sum]=take+not_take;
    }
    public int change(int amount, int[] coins) {
        int n=coins.length;
        int[][]dp = new int[n][amount+1];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(0,amount,n,coins,dp);
    }
}