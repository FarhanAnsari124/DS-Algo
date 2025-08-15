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
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return solve(0,n,-1,nums,dp);
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>=-1;prev--){
                int nt=0+dp[i+1][prev+1];
                int t=0;
                if(prev==-1 || nums[i]>nums[prev]){
                    t=1+dp[i+1][i+1];
                }
                dp[i][prev+1]=max(t,nt);
            }
        }
        return dp[0][0];
    }
};