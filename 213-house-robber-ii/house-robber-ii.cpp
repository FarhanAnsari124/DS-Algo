class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n+1,0);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int take=nums[i-1]+(i-2>=0 ? dp[i-2] :0);
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }
        int r1=dp[n-1];
        dp[1]=0;
        for(int i=2;i<=n;i++){
            int take=nums[i-1]+(i-2>=0 ? dp[i-2] :0);
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }
        return max(r1,dp[n]);

    }
};