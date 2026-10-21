class Solution {
public:
    int solve(int i,int prev,int ch,vector<int>&nums,vector<vector<vector<int>>>&dp){
        if(i==nums.size())return 0;
        if(prev!=-1 && dp[i][prev][ch]!=-1){
            return dp[i][prev][ch];
        }
        int skip=solve(i+1,prev,ch,nums,dp);
        int take=0;

        if(prev==-1){
            take=1+solve(i+1,i,!ch,nums,dp);
        }
        else if((ch==0 && nums[i]<nums[prev]) || (ch==1 && nums[i]>nums[prev])){
            take=1+solve(i+1,i,!ch,nums,dp);
        }
        int ans=max(take,skip);
        if(prev!=-1){
            dp[i][prev][ch]=ans;
        }
        return ans;
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return max(solve(0,-1,1,nums,dp),solve(0,-1,0,nums,dp));
    }
};