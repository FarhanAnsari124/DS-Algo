class Solution {
public:
    int solve(int i,int n,int canibuy,vector<int>& prices,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][canibuy]!=-1)return dp[i][canibuy];
        int profit=0;
        if(canibuy==1){
            profit=-prices[i]+solve(i+1,n,0,prices,dp);
            profit=max(profit,solve(i+1,n,1,prices,dp));
        }else{
            profit=prices[i]+solve(i+1,n,1,prices,dp);
            profit=max(profit,solve(i+1,n,0,prices,dp));
        }
        return dp[i][canibuy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,n,1,prices,dp);
    }
};