class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1e9)return dp[i][j];
        int down=triangle[i][j]+solve(i+1,j,n,triangle,dp);
        int diag=triangle[i][j]+solve(i+1,j+1,n,triangle,dp);

        return dp[i][j]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1e9));
        // return solve(0,0,n,triangle,dp);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i==0 && j==0)dp[i][j]=triangle[i][j];
                else{
                    int down=1e9,diag=1e9;
                    if(i>0 && i!=j)down=triangle[i][j]+dp[i-1][j];
                    if(j>0)diag=triangle[i][j]+dp[i-1][j-1];
                    
                    dp[i][j]=min(down,diag);
                }
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
        
    }
};