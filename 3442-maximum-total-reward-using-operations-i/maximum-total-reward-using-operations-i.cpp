class Solution {
public:
    int solve(int i,int n,int x,vector<int>& v ,vector<vector<int>>&dp){
        if(i==n){
            return x;
        }
        if(dp[i][x]!=-1)return dp[i][x];
        int t=x;
        if(x<v[i]){
            t=solve(i+1,n,x+v[i],v,dp);
        }
        int nt=0+solve(i+1,n,x,v,dp);
        return dp[i][x]=max(t,nt);
    }
    int maxTotalReward(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        vector<vector<int>>dp(2001,vector<int>(4001,-1));
        return solve(0,n,0,v,dp);
    }
};