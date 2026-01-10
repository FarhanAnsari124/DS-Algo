class Solution {
public:
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp,int m ,int n){
        if(i==m && j==n){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==m){
            return dp[i][j]=(int)s2[j]+solve(i,j+1,s1,s2,dp,m,n);
        }else if(j==n) return dp[i][j]=(int)s1[i]+solve(i+1,j,s1,s2,dp,m,n);
        else if(s1[i]==s2[j])return dp[i][j]=solve(i+1,j+1,s1,s2,dp,m,n);
        else return dp[i][j]=min((int)s1[i]+solve(i+1,j,s1,s2,dp,m,n),(int)s2[j]+solve(i,j+1,s1,s2,dp,m,n));
    }
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,s1,s2,dp,m,n);
    }
};