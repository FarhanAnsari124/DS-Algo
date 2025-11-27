class Solution {
public:
    int lis(int i,int pre,vector<int>&nums,vector<vector<int>>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][pre+1]!=-1)return dp[i][pre+1];
        int nt,t=0;
        nt=0+lis(i+1,pre,nums,dp);
        if(pre==-1 || nums[i]>nums[pre]){
            t=1+lis(i+1,i,nums,dp);
        }
        return dp[i][pre+1]=max(t,nt);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return lis(0,-1,nums,dp);
    }
};