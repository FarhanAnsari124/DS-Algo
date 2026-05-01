class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        int maxi=1;
        // return dp[n-1];
        for(auto x:dp){
            maxi=max(maxi,x);
        }
        return maxi;
    }
};