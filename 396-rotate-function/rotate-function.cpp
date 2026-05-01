class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            dp[0]+=(nums[i]*i);
            sum+=nums[i];
        }
        int maxi=dp[0];
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]+sum-(n*nums[n-i]);
            maxi=max(dp[i],maxi);
        }
        return maxi;
    }
};