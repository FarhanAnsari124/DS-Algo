class Solution {
public:
    int solve(int i,int n,int prev,vector<int>& nums,vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }
        if (dp[i][prev+1]!=-1)return dp[i][prev+1];
        int nt=0+solve(i+1,n,prev,nums,dp);
        int t=0;
        if(prev==-1 || nums[i]>nums[prev]){
            t=1+solve(i+1,n,i,nums,dp);
        }
        return dp[i][prev+1]=max(t,nt);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n,-1,nums,dp);
    }
};