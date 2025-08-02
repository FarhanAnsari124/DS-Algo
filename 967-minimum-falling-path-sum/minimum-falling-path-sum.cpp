class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(i==n-1)return matrix[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int d=matrix[i][j]+solve(i+1,j,n,matrix,dp);
        int ld=1e9,rd=1e9;
        if(j>0)ld=matrix[i][j]+solve(i+1,j-1,n,matrix,dp);
        if(j<n-1)rd=matrix[i][j]+solve(i+1,j+1,n,matrix,dp);
        return dp[i][j]=min({d,ld,rd});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=1e9;
        vector<vector<int>>dp(n,vector<int>(n,0));        
        // for(int j=0;j<n;j++){
        //     ans=min(ans,solve(0,j,n,matrix,dp));
        // }
        for(int j=0;j<n;j++){
            dp[n-1][j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int d=matrix[i][j]+dp[i+1][j];
                int ld=1e9,rd=1e9;
                if(j>0)ld=matrix[i][j]+dp[i+1][j-1];
                if(j<n-1)rd=matrix[i][j]+dp[i+1][j+1];
                dp[i][j]=min({d,ld,rd});
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};