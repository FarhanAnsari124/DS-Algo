class Solution {
public:
    int solve(int i,int t,vector<int>& c,vector<vector<int>>&dp){
        if(t==0)return 1;
        if(i==0){
            if(t%c[i]==0){
                return 1;
            }
            else return 0;
        }
        if(dp[i][t]!=-1)return dp[i][t];
        int nt=solve(i-1,t,c,dp);
        int take=0;
        if(t>=c[i])take=solve(i,t-c[i],c,dp);
        return dp[i][t]=take+nt;
    }
    int change(int amount, vector<int>& c) {
        int n=c.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,c,dp);
    }
};