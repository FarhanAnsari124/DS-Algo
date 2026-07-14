class Solution {
    public int solve(int i,int sum,int n,int[]coins,int[][]dp){
        if(i>=n){
            return (int)1e9;
        }
        if(i==n-1){
            if(sum%coins[i]==0){
                return dp[i][sum]=sum/coins[i];
            }
            else{
                return dp[i][sum]=(int)1e9;
            }
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int take=(int)1e9;
        if(coins[i]<=sum){
            take=1+solve(i,sum-coins[i],n,coins,dp);
        }
        int not_take = 0+ solve(i+1,sum,n,coins,dp);

        return dp[i][sum]=Math.min(take,not_take);

    }
    public int coinChange(int[] coins, int amount) {
        int n=coins.length;
        int [][]dp = new int[n][amount+1];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        int ans = solve(0,amount,n,coins,dp);
        if(ans>=(int)1e9){
            return -1;
        }
        else return ans;
    }
}