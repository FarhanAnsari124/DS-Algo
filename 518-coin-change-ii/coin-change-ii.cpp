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
        // return solve(n-1,amount,c,dp);
        int n=c.size();
        vector<unsigned long long>prev(amount+1,1);
        for(int t=0;t<=amount;t++){
            if(t%c[0]==0){
                prev[t]=1;
            }
            else prev[t]=0;
        }
        for(int i=1;i<n;i++){
            vector<unsigned long long>curr(amount+1,0);
            for(int t=0;t<=amount;t++){
                unsigned long long nt=prev[t];
                unsigned long long take=0;
                if(t>=c[i])take=curr[t-c[i]];
                curr[t]=nt+take;
            }
            prev=curr;
        }
        return prev[amount];
    }
};