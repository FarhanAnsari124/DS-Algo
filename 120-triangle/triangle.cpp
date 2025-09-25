class Solution {
public:
    int solve(int i,int n,vector<vector<int>>& triangle,int back,vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }
        if(dp[i][back]!=-1e9)return dp[i][back];
        int mini=1e9;
        for(int j=0;j<triangle[i].size();j++){
           if(j==back || j==back+1)mini=min(mini,triangle[i][j]+solve(i+1,n,triangle,j,dp));
        }
        return dp[i][back]=mini;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1e9));
        return solve(0,n,triangle,0,dp);
    }
};