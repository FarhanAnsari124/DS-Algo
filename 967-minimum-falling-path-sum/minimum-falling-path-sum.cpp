class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(i>m || j<0 || j>=n){
            return 1e9;
        }
        if(i==m-1)return mat[i][j];
        if(dp[i][j]!=-1){
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
        vector<vector<int>>dp(m,vector<int>(n,1e9));
        for(int i=0;i<n;i++)dp[m-1][i]=mat[m-1][i];
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int ld=1e9;
                int rd=1e9;
                if(j!=0)ld = mat[i][j]+dp[i+1][j-1];
                int d = mat[i][j]+dp[i+1][j];
                if(j!=n-1)rd = mat[i][j]+dp[i+1][j+1];
                dp[i][j]=min({ld,d,rd});
            }
        }
        for(int i=0;i<n;i++){
            mini=min(mini,dp[0][i]);
        }
        return mini;
    }
};