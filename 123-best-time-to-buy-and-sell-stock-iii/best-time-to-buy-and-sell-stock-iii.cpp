class Solution {
public:
    int solve(int i,int n,bool canibuy,int cap,vector<int>& p,vector<vector<vector<int>>>&dp){
        if(i==n || cap==0)return 0;
        int profit=0;
        if(dp[i][canibuy][cap]!=-1)return dp[i][canibuy][cap];
        if(canibuy && cap){
            profit=-p[i]+solve(i+1,n,0,cap,p,dp);
            profit=max(profit,solve(i+1,n,1,cap,p,dp));
        }
        else if(cap){
            profit=p[i]+solve(i+1,n,1,cap-1,p,dp);
            profit=max(profit,solve(i+1,n,0,cap,p,dp));
        }
        return dp[i][canibuy][cap]=profit;
    }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,n,1,2,p,dp);
    }
};