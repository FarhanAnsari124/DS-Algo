class Solution {
public:
     int solve(int i,int n,bool canibuy,int fee,vector<int>& p,vector<vector<int>>&dp){
        if(i>=n)return 0;
        int profit=0;
        if(dp[i][canibuy]!=-1)return dp[i][canibuy];
        if(canibuy){
            profit=-p[i]+solve(i+1,n,0,fee,p,dp);
            profit=max(profit,solve(i+1,n,1,fee,p,dp));
        }
        else{
            profit=p[i]-fee+solve(i+1,n,1,fee,p,dp);
            profit=max(profit,solve(i+1,n,0,fee,p,dp));
        }
        return dp[i][canibuy]=profit;
    }
    int maxProfit(vector<int>& p, int fee) {
        int n=p.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,n,1,fee,p,dp);
    }
};