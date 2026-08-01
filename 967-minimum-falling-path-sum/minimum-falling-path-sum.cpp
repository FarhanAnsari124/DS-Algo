class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(j<0 || j>=n){
            return 1e9;
        }
        if(i==m-1)return mat[i][j];
        if(dp[i][j]!=-101){
            return dp[i][j];
        }
        int ld = mat[i][j]+solve(i+1,j-1,m,n,mat,dp);
        int d = mat[i][j]+solve(i+1,j,m,n,mat,dp);
        int rd = mat[i][j]+solve(i+1,j+1,m,n,mat,dp);
        return dp[i][j]=min({ld,d,rd});
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int mini=1e9;
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-101));
        for(int i=0;i<n;i++){
            mini=min(solve(0,i,m,n,mat,dp),mini);
        }
        return mini;
    }
};