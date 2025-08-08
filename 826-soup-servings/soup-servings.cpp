class Solution {
public:
    double solve(int a,int b,int n,vector<vector<double>>&dp){
        if(a>=n && b>=n)return 0.5;
        if(a>=n && b<n)return 1;
        if(a<n && b>=n)return 0;
        if(dp[a][b]!=-1)return dp[a][b];
        double o1=solve(a+100,b+0,n,dp);
        double o2=solve(a+75,b+25,n,dp);
        double o3=solve(a+50,b+50,n,dp);
        double o4=solve(a+25,b+75,n,dp);

        return dp[a][b]=0.25*(o1+o2+o3+o4);
    }
    double soupServings(int n) {
        if (n >= 5000) return 1.0;
        vector<vector<double>>dp(5000,vector<double>(5000,-1));
        return solve(0,0,n,dp);
    }
};