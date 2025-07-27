class Solution {
public:
    int solve(int ind,int n,vector<int>&nums,vector<int>&dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        int pick=nums[ind]+solve(ind+2,n,nums,dp);
        int not_pick=solve(ind+1,n,nums,dp);
        return dp[ind]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n+1,-1);
       int ans=solve(0,n-1,nums,dp);
       dp=vector<int>(n+1,-1);
       int ans2=solve(1,n,nums,dp);
        return max(ans,ans2);
    }
};