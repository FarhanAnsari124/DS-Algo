class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums)sum+=x;
        int t=sum/2;
        if(sum%2!=0)return false;
        vector<int>prev(t+1,0);
        prev[0] = true;
        // if (nums[0] <= t)
        // dp[0][nums[0]] = true;
        if(nums[0]<=t)prev[nums[0]]=true;
        for(int i=1;i<n;i++){
            vector<int>dp(t+1,0);
            for(int target=1;target<=t;target++){
                int exclude = prev[target];
                int include=0;
                if(target-nums[i]>=0){
                    include = prev[target-nums[i]];
                }
                dp[target] = include||exclude;
            }
            prev = dp;
        }
        return prev[t];
    }
};