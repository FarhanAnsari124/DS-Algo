class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums)sum+=x;
        int t=sum/2;
        if(sum%2!=0)return false;
        vector<vector<int>>dp(n,vector<int>(t+1,0));
        for (int i = 0; i < n; i++) {
                dp[i][0] = true;
            }
        if (nums[0] <= t)
        dp[0][nums[0]] = true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=t;target++){
                int exclude = dp[i-1][target];
                int include=0;
                if(target-nums[i]>=0){
                    include = dp[i-1][target-nums[i]];
                }
                dp[i][target] = include||exclude;
            }
        }
        return dp[n-1][t];
    }
};