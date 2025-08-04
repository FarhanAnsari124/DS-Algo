class Solution {
public:
    int solve(int i,int j1,int j2,vector<vector<int>>& g,int n,int m,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=m || j2<0 || j2>=m){
            return -1e9;
        }
        if(i==n-1){
            if(j1==j2)return g[i][j1];
            else return g[i][j1]+g[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int maxi=-1e8;
        for(int d1=-1;d1<=1;d1++){
            for(int d2=-1;d2<=1;d2++){
                if(j1==j2) maxi=max(maxi,g[i][j1]+solve(i+1,j1+d1,j2+d2,g,n,m,dp));
                else maxi=max(maxi,g[i][j1]+g[i][j2]+solve(i+1,j1+d1,j2+d2,g,n,m,dp));
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(0,0,m-1,g,n,m,dp);
        
    }
};