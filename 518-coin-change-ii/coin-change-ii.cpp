class Solution {
public:
    int solve(int i,int t,vector<int>& c,vector<vector<int>>&dp){
        if(t==0)return 1;
        if(i==0){
            if(t%c[0]==0){
                return 1;
            }
            else return 0;
        }
        if(dp[i][t]!=-1)return dp[i][t];
        int nt=solve(i-1,t,c,dp);
        int take=0;
        if(t>=c[i])take=solve(i,t-c[i],c,dp);
        return dp[i][t]=take+nt;
    }
    int change(int amount, vector<int>& c) {
        int n=c.size();
        vector<vector<double>>dp(n,vector<double>(amount+1,1));
        // return solve(n-1,amount,c,dp);
        for(int t=0;t<=amount;t++){
            if(t%c[0]==0){
                dp[0][t]=1;
            }
            else dp[0][t]=0;
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                double nt=dp[i-1][t];
                double take=0;
                if(t>=c[i])take=dp[i][t-c[i]];
                dp[i][t]=nt+take;
            }
        }
        return dp[n-1][amount];
    }
};