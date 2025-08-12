class Solution {
public:
    int MOD=1000000007;
    int solve(int n,int num,int x,vector<vector<int>>&dp){
        if(n==0)return 1;
        if(n<0)return 0;
        if((long long)pow(num,x)>n)return 0;
        if(dp[num][n]!=-1)return dp[num][n];
        int nt=solve(n,num+1,x,dp);
        int t=solve(n-(long long)pow(num,x),num+1,x,dp);
        return dp[num][n]=(t+nt)%MOD;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(301,vector<int>(301,-1));
        return solve(n,1,x,dp);
    }
};