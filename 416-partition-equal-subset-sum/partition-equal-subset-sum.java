class Solution {
    public int solve(int i,int sum,int n,int[]arr,int[][]dp){
        if(i>=n){
            return 0;
        }
        if(sum==arr[i]){
            return dp[i][sum]=1;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int take=0;
        if(arr[i]<=sum){
            take=solve(i+1,sum-arr[i],n,arr,dp);
        }
        int not_take=solve(i+1,sum,n,arr,dp);
        return dp[i][sum]=take | not_take;
    }
    public boolean canPartition(int[] nums) {
        int n=nums.length;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        sum = sum/2;
        int [][]dp = new int[n][sum+1];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        if(solve(0,sum,n,nums,dp)==1){
            return true;
        }else{
            return false;
        }
    }
}