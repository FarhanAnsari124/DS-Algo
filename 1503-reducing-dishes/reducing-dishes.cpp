class Solution {
public:
    int solve(int i,int k,vector<int>&v,vector<vector<int>>&dp){
        if(i==v.size()){
            return 0;
        }
        if(dp[i][k]!=-1)return dp[i][k];
        int nt = solve(i+1,k,v,dp);
        int take = (v[i]*k) + solve(i+1,k+1,v,dp);
        return dp[i][k] =  max(nt,take);
    }
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,1,v,dp);
    }
};