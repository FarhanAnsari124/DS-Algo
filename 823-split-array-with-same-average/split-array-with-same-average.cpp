class Solution {
public:
    bool solve(int i,int sum,int k,int tot,int n,vector<int>&nums,vector<vector<vector<int>>>&dp){
        if(k!=0 && k!=n && (double)sum/k == (double)(tot-sum)/(n-k)){
            return dp[i][sum][k]=true;
        }
        if(dp[i][sum][k]!=-1){
            return dp[i][sum][k];
        }
        if(i>=n){
            return false;
        }
        return dp[i][sum][k]=solve(i+1,sum+nums[i],k+1,tot,n,nums,dp) || solve(i+1,sum,k,tot,n,nums,dp);
    }
    bool splitArraySameAverage(vector<int>& nums) {
        int n=nums.size();
        int tot=0;
        for(auto x:nums)tot+=x;
        vector<vector<int>>dp(n+1,vector<int>(tot+1,0));
        dp[0][0]=1;
        for(auto x:nums){
            for(int k=n-1;k>=0;k--){
                for(int sum=tot-x;sum>=0;sum--){
                    if(dp[k][sum]){
                        dp[k+1][sum+x]=1;
                    }
                }
            }
        }

        for(int k=1;k<n;k++){
            if((tot*k)%n==0){
                int sum=(tot*k)/n;

                if(dp[k][sum]){
                    return true;
                }
            }
        }
        // return solve(0,0,0,tot,n,nums,dp);
        return false;
    }
};